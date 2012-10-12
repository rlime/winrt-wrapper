#pragma once

#include "Object.h"
#include "Windows.ApplicationModel.Activation.Events.h"
#include "Windows.Foundation.h"
#include <Windows.UI.Xaml.h>

/*namespace Windows { namespace UI { namespace Xaml {
	struct IUIElement;
}}};*/

namespace Windows { namespace UI { namespace Xaml {

	//Application
	class Application : public Object {
	public:	
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::IApplication)
		
		Application();
		Application(IInspectable* core);
		~Application();
		
		static void Start();		
		static void LoadComponent(const Object* obj, const Windows::Foundation::Uri* uri);
		//static winrt_ptr<Application> GetCurrent();				

	public:
		virtual void OnActivated(ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs *args);
		virtual void OnLaunched(ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args);
		virtual void OnFileActivated(ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args);
		virtual void OnSearchActivated(ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args);
		virtual void OnShareTargetActivated(ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args);
		virtual void OnFileOpenPickerActivated(ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs *args);		
		virtual void OnFileSavePickerActivated(ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs *args);		
		virtual void OnCachedFileUpdaterActivated(ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs *args);		
		virtual void OnWindowCreated(ABI::Windows::UI::Xaml::IWindowCreatedEventArgs *args);		
		

	//private:
		Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IApplicationOverrides> _overrides;
		Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IApplication> _application;
	};

	//UIElement
	class UIElement : public Object
	{
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::IUIElement)

		UIElement(IInspectable* core);
	};

	//FrameworkElement
	class FrameworkElement : public UIElement {
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::IFrameworkElement)
		
		FrameworkElement(IInspectable* core);		
		
		double GetWidth();
		void SetWidth(double w);

		Object* FindName(const std::wstring& str);		
	};

	//Window
	class Window : public Object {
	public:				
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::IWindow)
		
		Window(IInspectable* core);
		
		void Activate();
		void Close();		
		void SetContent(const UIElement* pNode);
		UIElement* GetContent();

		static Window* GetCurrent();
		
	};

	//RoutedEventArgs
	class RoutedEventArgs : public Object {
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::IRoutedEventArgs)

		RoutedEventArgs(IInspectable* core);
		Object* GetOriginalSource();
	};

}}}
