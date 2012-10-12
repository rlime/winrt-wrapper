#pragma once

#include "Object.h"
#include <Windows.UI.Xaml.h>

namespace Windows { namespace UI { namespace Xaml {
	class Application;
	class RoutedEventArgs;
}}}

namespace Export { 
namespace Windows { namespace UI { namespace Xaml {

	class ApplicationOverrides :
		public Microsoft::WRL::RuntimeClass<ABI::Windows::UI::Xaml::IApplicationOverrides>
	{
		InspectableClass(L"Export.Windows.UI.Xaml.ApplicationOverrides", TrustLevel::BaseTrust)
		::Windows::UI::Xaml::Application* impl_;

	public:
		ApplicationOverrides(::Windows::UI::Xaml::Application* impl) : impl_(impl) {}

		//virtual void AddRef();
		//virtual void Release();

		virtual HRESULT STDMETHODCALLTYPE OnActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnLaunched( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnFileActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnSearchActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnShareTargetActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnFileOpenPickerActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnFileSavePickerActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnCachedFileUpdaterActivated( 
            /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs *args);
                        
        virtual HRESULT STDMETHODCALLTYPE OnWindowCreated( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IWindowCreatedEventArgs *args);
                        
	};

	class RoutedEventHandler :
		public Microsoft::WRL::RuntimeClass<
			Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::Delegate>, 
			ABI::Windows::UI::Xaml::IRoutedEventHandler
		>
	{
	public:
		typedef std::function<void (Object*, ::Windows::UI::Xaml::RoutedEventArgs* args)> Callback_t;
		std::vector<Callback_t> handlers_;

		HRESULT STDMETHODCALLTYPE Invoke(IInspectable* sender, ABI::Windows::UI::Xaml::IRoutedEventArgs* args);
	};

}}}}
