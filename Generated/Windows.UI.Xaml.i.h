#pragma once

#include "Object.i.h"
#include "Windows.ApplicationModel.Activation.Events.i.h"
#include "Windows.Foundation.i.h"
#include <Windows.UI.Xaml-coretypes.h>

/*namespace Windows { namespace UI { namespace Xaml {
	struct IUIElement;
}}};*/

namespace Import { 
namespace Windows { namespace UI { namespace Xaml {

	//Application
	class Application : public Import::Object {
	public:	
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::IApplication)
		
		Application();
		Application(IInspectable* core);
		~Application();
		
		void Run();
		
		virtual void OnInitialize();
		virtual void OnActivated(::Windows::ApplicationModel::Activation::IActivatedEventArgs *args);
		virtual void OnLaunched(::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args);
		virtual void OnFileActivated(::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args);
		virtual void OnSearchActivated(::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args);
		virtual void OnSharingTargetActivated(::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args);
		virtual void OnFilePickerActivated(::Windows::ApplicationModel::Activation::IFilePickerActivatedEventArgs *args);		

		static void LoadComponent(const winrt_ptr<Import::Object>& obj, const winrt_ptr<Import::Windows::Foundation::Uri>& uri);
		//static winrt_ptr<Application> GetCurrent();		

	//private:
		Microsoft::WRL::ComPtr<::Windows::UI::Xaml::IApplicationOverrides> _overrides;
		Microsoft::WRL::ComPtr<::Windows::UI::Xaml::IApplication> _application;
	};

	//FrameworkElement
	class FrameworkElement : public Import::Object {
	public:
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::IFrameworkElement)
		
		FrameworkElement(IInspectable* core);		
		winrt_ptr<Import::Object> FindName(const std::wstring& str);		
	};

	//Window
	class Window : public Import::Object {
	public:				
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::IWindow)
		
		Window(IInspectable* core);
		
		void Activate();
		void Close();		
		void SetContent(const winrt_ptr<Import::Object>& pNode);

		static winrt_ptr<Window> GetCurrent();
		
	};

}}}}
