#pragma once

#include <functional>
#include <vector>
#include <cassert>
#include <wrl.h>
#include <wrl/def.h>
//#include <wrl/internal.h> //Details::EnableIf

class Object
{
public:
	Object() {}
	Object(IInspectable* ptr) { SetInspectable(ptr); }
	virtual ~Object() 
	{
		int a = 5;
	}

	template <class T>
	void SetInspectable(const Microsoft::WRL::ComPtr<T>& ptr) //IInspectable* ptr)
	{
		inspectable_ = ptr;
	}

	//Microsoft::WRL::ComPtr<IInspectable> GetInspectable() const 
	IInspectable* GetInspectable() const 
	{ 
		return inspectable_.Get(); 
	}

protected:
	virtual ULONG AddRef()
	{
		if (!inspectable_) return 0;
		return inspectable_.Get()->AddRef();
	}

	virtual ULONG Release()
	{
		if (!inspectable_) return 0;
		return inspectable_.Get()->Release();
	}

private:
	void SetInspectable(IInspectable* ptr)
	{
		inspectable_ = ptr;
	}

private:
	Microsoft::WRL::ComPtr<IInspectable> inspectable_;
};

#define DECLARE_DEFAULT_INTERFACE(DefaultInterface) \
	typedef DefaultInterface DefaultInterface_t; \
	Microsoft::WRL::ComPtr<DefaultInterface_t> GetDefaultInterface() const; \

#define IMPLEMENT_DEFAULT_INTERFACE(ClassName) \
	Microsoft::WRL::ComPtr<ClassName::DefaultInterface_t> ClassName::GetDefaultInterface() const { \
		Microsoft::WRL::ComPtr<DefaultInterface_t> pTemp; \
		api::CheckHR(GetInspectable()->QueryInterface(__uuidof(DefaultInterface_t), &pTemp)); \
		return pTemp; \
	} \

template<class U>
U* winrt_cast(const Object* ptr)
{
	if (!ptr) return nullptr;
	
	typename U::DefaultInterface_t* tmp; 
	api::CheckHR(ptr->GetInspectable()->QueryInterface(__uuidof(typename U::DefaultInterface_t), (void**)&tmp)); 

	return Create<U>(ptr->GetInspectable());
}

//Create
template <class ImportType>
ImportType* Create(IInspectable* core) {
	if (!core) return nullptr;
	return new ImportType(core);
}

/*
//property_rw
template <class T, class C, void (C::* setter)(T), T (C::* getter)())
class property_rw {
public:
	property_rw() : _impl(nullptr) {}
	void init(C* impl) { _impl = impl; }

	property_rw& operator= (const T& value)
	{
		(_impl->*setter)(value);
		return *this;
	}
	operator T ()
	{
		return (_impl->*getter)();
	}

private:
	C*	_impl;
};

//static_property_rw
template <class T, void (* setter)(T), T (* getter)())
class property_srw {
public:
	property_srw& operator= (const T& value)
	{
		setter(value);
		return *this;
	}
	operator T ()
	{
		return getter();
	}
};
*/

template <class EventHandler>
class winrt_event {
private:
	class helper_base {
	public:
		virtual ~helper_base() {}
		virtual EventRegistrationToken register_handler(EventHandler*) = 0;
		virtual void unregister_handler(EventRegistrationToken) = 0;
	};

	template <class Object>
	class helper : public helper_base {
	public:
		typedef EventRegistrationToken (Object::* register_fun_t) (EventHandler*);
		typedef void (Object::* unregister_fun_t) (EventRegistrationToken);

		helper(Object* obj, register_fun_t reg, unregister_fun_t unreg)
			: object_(obj), register_fun_(reg), unregister_fun_(unreg) 
		{
		}
		EventRegistrationToken register_handler(EventHandler* handler)
		{
			return (object_->*register_fun_)(handler);
		}
		void unregister_handler(EventRegistrationToken token)
		{
			(object_->*unregister_fun_)(token);
		}

	private:
		Object* object_;
		register_fun_t register_fun_;
		unregister_fun_t unregister_fun_;
	};

public:
	typedef typename EventHandler::Callback_t callback_t;	
	
	winrt_event() : helper_(nullptr) 
	{
		token_.value = 0;
	}
	
	~winrt_event() 
	{
		if (token_.value) 
			helper_->unregister_handler(token_);
		delete helper_;
	}
	
	template <class Object>
	void init(
		Object* object, 
		EventRegistrationToken (Object::* register_fun) (EventHandler*), 
		void (Object::* unregister_fun) (EventRegistrationToken)) 
	{
		assert(!helper_);
		helper_ = new helper<Object>(object, register_fun, unregister_fun);
	}
	
	void connect(callback_t clb) 
	{
		assert(helper_);
		if (!handler_) {
			handler_ = Microsoft::WRL::Make<EventHandler>();		
			token_ = helper_->register_handler(handler_.Get());
		}
		handler_->handlers_.push_back(clb);
	}

	void disconnect_all() 
	{
		if (!handler_) return;
		handler_->handlers_.clear();
	}

protected:
	helper_base* helper_;
	Microsoft::WRL::ComPtr<EventHandler> handler_;
	EventRegistrationToken token_;
};

/*
template <class T>
struct ExtractFuncType
{};

template <class T>
struct ExtractFuncType<std::function<T>>
{
	typedef T type;
};
*/
