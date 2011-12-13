#pragma once

#include <functional>
#include <wrl.h>
#include <wrl/def.h>
#include <wrl/internal.h> //Details::EnableIf

namespace Import {

//Make
template <class ImportType>
ImportType* Create(IInspectable* core) {
	if (!core) return nullptr;
	return new ImportType(core);
}

//Object
class Object
{
public:
	Object();
	Object(IInspectable* core);
	virtual ~Object();

	IInspectable* GetCoreObj() const { return _core; }

	int AddRef();
	int Release();

protected:
	void Attach(IInspectable* obj);
	void DebugClearCore() { _core = nullptr; }

private:
	IInspectable* _core;
	//Microsoft::WRL::ComPtr<InterfaceType> _core;
	int _ref_count;
};

}

#define DECLARE_CORE_TYPE(CoreType) \
	typedef CoreType CoreType_t; \
	Microsoft::WRL::ComPtr<CoreType_t> GetCoreObj() const; \

#define IMPLEMENT_CORE_TYPE(ClassName) \
	Microsoft::WRL::ComPtr<ClassName::CoreType_t> ClassName::GetCoreObj() const { \
		Microsoft::WRL::ComPtr<CoreType_t> pTemp; \
		api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(CoreType_t), &pTemp)); \
		return pTemp; \
	} \

//winrt_ptr
template <class T>
class winrt_ptr {
public:
	winrt_ptr()
	{
		_impl = nullptr;		
	}

	winrt_ptr(T* impl)
	{
		_impl = impl;		
	}

	winrt_ptr(const winrt_ptr& ptr)
	{
		_impl = ptr._impl;
		AddRef();
	}

	template <class U>
	winrt_ptr(const winrt_ptr<U>& ptr, typename Microsoft::WRL::Details::EnableIf<__is_convertible_to(U*, T*), void*>::type* = 0)
	{
		_impl = ptr._impl;
		AddRef();
	}

	/*template <class U>
	winrt_ptr(winrt_ptr&& ptr, typename Microsoft::WRL::Details::EnableIf<__is_convertible_to(U*, T*), void*>::type* = 0)
	{
		_impl = ptr._impl;
		ptr._impl = nullptr;		
	}*/

	~winrt_ptr()
	{
		Release();
	}

	winrt_ptr& operator= (const winrt_ptr& ptr)
	{
		Release();
		_impl = ptr._impl;
		AddRef();
		return *this;
	}

	template <class U>
	typename Microsoft::WRL::Details::EnableIf<__is_convertible_to(U*, T*), winrt_ptr&>::type
	operator= (const winrt_ptr<U>& ptr)
	{
		Release();
		_impl = ptr._impl;
		AddRef();
		return *this;
	}

	/*template <class U>
	typename Microsoft::WRL::Details::EnableIf<__is_convertible_to(U*, T*), winrt_ptr&>::type
	operator= (winrt_ptr<U>&& ptr)
	{
		Release();
		_impl = ptr._impl;
		ptr._impl = nullptr;
		return *this;
	}*/

	T* get()
	{
		return _impl;
	}

	const T* get() const
	{
		return _impl;
	}

	T* operator-> ()
	{
		return _impl;
	}

	const T* operator-> () const
	{
		return _impl;
	}

private:
	void AddRef()
	{
		if (_impl)
			_impl->AddRef();
	}
	void Release() 
	{
		if (_impl) {
			_impl->Release();
			_impl = nullptr;
		}
	}

	template <class U> friend class winrt_ptr;
	T*	_impl;	
};


template<class U, class T>
winrt_ptr<U> winrt_cast(const winrt_ptr<T>& ptr)
{
	return Import::Create<U>(ptr->GetCoreObj());
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

template <class F, class C>
class winrt_event {
public:
	typedef std::function<F> callback_t;
	typedef EventRegistrationToken (C::* add_handler_t) (callback_t);
	typedef void (C::* remove_handler_t) (EventRegistrationToken);

	winrt_event() {
		_token.value = 0;
	}
	virtual ~winrt_event() {
	}
	void init(C* object, add_handler_t add_handler, remove_handler_t remove_handler) {
		_object = object;
		_add_handler = add_handler;
		_remove_handler = remove_handler;
	}
	void connect(callback_t clb) {
		disconnect();
		_token = (_object->*_add_handler)(clb);
	}
	void disconnect() {
		if (_token.value)
			(_object->*_remove_handler)(_token);					
	}

protected:
	EventRegistrationToken _token;
	C* _object;
	add_handler_t _add_handler;
	remove_handler_t _remove_handler;
};

template <class T>
struct ExtractFuncType
{};

template <class T>
struct ExtractFuncType<std::function<T>>
{
	typedef T type;
};

