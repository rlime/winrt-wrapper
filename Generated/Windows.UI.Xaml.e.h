#pragma once

#include "Object.i.h"
#include <Windows.UI.Xaml-coretypes.h>

namespace Import {
namespace Windows { namespace UI { namespace Xaml {
	class Application;
}}}}

namespace Export { 
namespace Windows { namespace UI { namespace Xaml {

	class ApplicationOverrides :
		public Microsoft::WRL::RuntimeClass<::Windows::UI::Xaml::IApplicationOverrides>
	{
		InspectableClass(L"Export.Windows.UI.Xaml.ApplicationOverrides", TrustLevel::BaseTrust)
		Import::Windows::UI::Xaml::Application* _impl;

	public:
		ApplicationOverrides(Import::Windows::UI::Xaml::Application* impl) : _impl(impl) {}

		//virtual void AddRef();
		//virtual void Release();

		HRESULT STDMETHODCALLTYPE OnInitialize();
		HRESULT STDMETHODCALLTYPE OnActivated(::Windows::ApplicationModel::Activation::IActivatedEventArgs *args);
		HRESULT STDMETHODCALLTYPE OnLaunched(::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args);
		HRESULT STDMETHODCALLTYPE OnFileActivated(::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args);
		HRESULT STDMETHODCALLTYPE OnSearchActivated(::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args);
		HRESULT STDMETHODCALLTYPE OnSharingTargetActivated(::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args);
		HRESULT STDMETHODCALLTYPE OnFilePickerActivated(::Windows::ApplicationModel::Activation::IFilePickerActivatedEventArgs *args);
	};

	class RoutedEventHandler :
		public Microsoft::WRL::RuntimeClass<
			Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::Delegate>, 
			::Windows::UI::Xaml::IRoutedEventHandler
		>
	{
	public:
		typedef std::function<void (const winrt_ptr<Import::Object>&, ::Windows::UI::Xaml::IRoutedEventArgs* args)> Callback_t;
		typedef ExtractFuncType<Callback_t>::type FuncType_t;		

	public:
		RoutedEventHandler(Callback_t clb) : _callback(clb) {}

		HRESULT STDMETHODCALLTYPE Invoke(IInspectable* sender, ::Windows::UI::Xaml::IRoutedEventArgs* args)
		{
			try {
				_callback(Import::Create<Import::Object>(sender), args);
				return 0;
			}
			catch (...) {
				return -1;
			}
		}

	private:
		Callback_t _callback;
	};

}}}}
