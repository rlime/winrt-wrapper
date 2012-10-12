#include "pch.h"
#include "Windows.UI.Xaml.h"
#include "Windows.UI.Xaml.e.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace Windows::Foundation;

using namespace ABI::Windows::UI::Xaml;

namespace Windows { namespace UI { namespace Xaml {

//------------------------------------------------------------------------------------------
// Application
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(Application)

Application::Application(IInspectable* core)
: Object(core)
{
}

Application::Application()
: Object(nullptr)
{
	ComPtr<IActivationFactory> activationFactory;
	api::CheckHR(GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Application"), &activationFactory));
	
	ComPtr<IApplicationFactory> applicationFactory;
	api::CheckHR(activationFactory.As(&applicationFactory));

	//ComPtr<IApplicationOverrides> pApplicationOverrides = 
	_overrides = Make<Export::Windows::UI::Xaml::ApplicationOverrides>(this);

	ComPtr<IInspectable> inner;
	//ComPtr<IApplication> pApplication;
	api::CheckHR(applicationFactory->CreateInstance(
		_overrides.Get(),
		&inner,
		&_application //pApplication
	));
	
	//we have to hold both pApplication and _inner
	SetInspectable(inner); 

	/*ComPtr<IApplication> pApp;
	ComPtr<IInspectable> pInsp;
	api::CheckHR(_inner.As(&pApp));*/
}

Application::~Application()
{
	//Release fails after _inner is released
	//Attach(nullptr);
}

void Application::Start()
{
	ComPtr<IApplicationStatics> applicationStatics;
	api::CheckHR(GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Application"), &applicationStatics));
	
	api::CheckHR(applicationStatics->Start(nullptr));
}

void Application::LoadComponent(const Object* obj, const Windows::Foundation::Uri* uri)
{
	ComPtr<IActivationFactory> activationFactory;
	api::CheckHR(GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Application"), &activationFactory));
	
	ComPtr<IApplicationStatics> applicationStatics;
	api::CheckHR(activationFactory.As(&applicationStatics));

	api::CheckHR(applicationStatics->LoadComponent(obj->GetInspectable(), uri->GetDefaultInterface().Get()));	
}

/*winrt_ptr<Application> Application::GetCurrent()
{
	ComPtr<::Windows::UI::Xaml::IApplicationStatics> pApplicationStatics;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Application"), &pApplicationStatics));

	ComPtr<::Windows::UI::Xaml::IApplication> pApplication;
	api::CheckHR(pApplicationStatics->get_Current(&pApplication));
	return FindOrCreate<Application>(pApplication.Get());
}*/


void Application::OnActivated(ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnActivated(args));
}

void Application::OnLaunched(ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnLaunched(args));
}

void Application::OnFileActivated(ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnFileActivated(args));
}

void Application::OnSearchActivated(ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnSearchActivated(args));
}

void Application::OnShareTargetActivated(ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnShareTargetActivated(args));
}

void Application::OnFileOpenPickerActivated(ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs *args)		
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnFileOpenPickerActivated(args));
}

void Application::OnFileSavePickerActivated(ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs *args)		
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnFileSavePickerActivated(args));
}

void Application::OnCachedFileUpdaterActivated(ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs *args)		
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnCachedFileUpdaterActivated(args));
}

void Application::OnWindowCreated(ABI::Windows::UI::Xaml::IWindowCreatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(GetInspectable()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnWindowCreated(args));
}

//------------------------------------------------------------------------------------------
// UIElement
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(UIElement)

UIElement::UIElement(IInspectable* core)
: Object(core)
{
}

//------------------------------------------------------------------------------------------
// FrameworkElement
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(FrameworkElement)

FrameworkElement::FrameworkElement(IInspectable* core)
: UIElement(core)
{
}

double FrameworkElement::GetWidth()
{
	DOUBLE w;
	api::CheckHR(GetDefaultInterface()->get_Width(&w));
	return w;
}

void FrameworkElement::SetWidth(double w)
{
	api::CheckHR(GetDefaultInterface()->put_Width(w));
}

Object* FrameworkElement::FindName(const std::wstring& str)
{
	ComPtr<IInspectable> pResult;
	api::CheckHR(GetDefaultInterface()->FindName(api::ProperHSTRING(str), &pResult));

	return Create<Object>(pResult.Get());
}

//------------------------------------------------------------------------------------------
// Window
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(Window)

Window::Window(IInspectable* core)
: Object(core)
{	
}

Window* Window::GetCurrent()
{
	ComPtr<ABI::Windows::UI::Xaml::IWindowStatics> pWindowStatics;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Window"), &pWindowStatics));

	ComPtr<ABI::Windows::UI::Xaml::IWindow> pResult;
	api::CheckHR(pWindowStatics->get_Current(&pResult));

	return Create<Window>(pResult.Get());
}		

void Window::Activate()
{
	api::CheckHR(GetDefaultInterface()->Activate());
}

void Window::Close()
{
	api::CheckHR(GetDefaultInterface()->Close());
}

void Window::SetContent(const UIElement* pElement)
{
	api::CheckHR(GetDefaultInterface()->put_Content(pElement->GetDefaultInterface().Get()));
}

UIElement* Window::GetContent()
{
	ComPtr<ABI::Windows::UI::Xaml::IUIElement> pElement;
	api::CheckHR(GetDefaultInterface()->get_Content(&pElement));
	return Create<UIElement>(pElement.Get());
}

//------------------------------------------------------------------------------------------
// RoutedEventArgs
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(RoutedEventArgs)

RoutedEventArgs::RoutedEventArgs(IInspectable* core)
: Object(core)
{	
}

}}}