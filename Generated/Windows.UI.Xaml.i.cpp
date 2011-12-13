#include "Windows.UI.Xaml.i.h"
#include "Windows.UI.Xaml.e.h"

using namespace Microsoft::WRL;
using namespace Windows::UI::Xaml;

namespace Import { 
namespace Windows { namespace UI { namespace Xaml {

//------------------------------------------------------------------------------------------
// Application
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(Application)

Application::Application(IInspectable* core)
: Object(core)
{
}

Application::Application()
: Object(nullptr)
{
	ComPtr<IApplicationFactory> pFactory;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Application"), &pFactory));
	
	//ComPtr<IApplicationOverrides> pApplicationOverrides = 
	_overrides = Make<Export::Windows::UI::Xaml::ApplicationOverrides>(this);

	ComPtr<IInspectable> pInner;
	//ComPtr<IApplication> pApplication;
	api::CheckHR(pFactory->CreateInstance(
		_overrides.Get(),
		&pInner,
		&_application //pApplication
	));
	
	//we have to hold both pApplication and _inner
	Attach(pInner.Get()); 

	/*ComPtr<IApplication> pApp;
	ComPtr<IInspectable> pInsp;
	api::CheckHR(_inner.As(&pApp));*/
}

Application::~Application()
{
	//Release fails after _inner is released
	//Attach(nullptr);
}

void Application::LoadComponent(const winrt_ptr<Import::Object>& obj, const winrt_ptr<Import::Windows::Foundation::Uri>& uri)
{
	ComPtr<::Windows::UI::Xaml::IApplicationStatics> pApplicationStatics;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Application"), &pApplicationStatics));

	api::CheckHR(pApplicationStatics->LoadComponent(obj->GetCoreObj(), uri->GetCoreObj().Get()));	
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

void Application::Run()
{
	api::CheckHR(GetCoreObj()->Run());
}

void Application::OnInitialize()
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnInitialize());
}

void Application::OnActivated(::Windows::ApplicationModel::Activation::IActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnActivated(args));
}

void Application::OnLaunched(::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnLaunched(args));
}

void Application::OnFileActivated(::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnFileActivated(args));
}

void Application::OnSearchActivated(::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnSearchActivated(args));
}

void Application::OnSharingTargetActivated(::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnSharingTargetActivated(args));
}

void Application::OnFilePickerActivated(::Windows::ApplicationModel::Activation::IFilePickerActivatedEventArgs *args)
{
	ComPtr<IApplicationOverrides> pApplicationOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IApplicationOverrides), &pApplicationOverrides));
	api::CheckHR(pApplicationOverrides->OnFilePickerActivated(args));
}

//------------------------------------------------------------------------------------------
// FrameworkElement
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(FrameworkElement)

FrameworkElement::FrameworkElement(IInspectable* core)
: Object(core)
{
}

winrt_ptr<Object> FrameworkElement::FindName(const std::wstring& str)
{
	ComPtr<IInspectable> pResult;
	api::CheckHR(GetCoreObj()->FindName(api::ProperHSTRING(str), &pResult));

	return Import::Create<Object>(pResult.Get());
}

//------------------------------------------------------------------------------------------
// Window
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(Window)

Window::Window(IInspectable* core)
: Object(core)
{	
}

winrt_ptr<Window> Window::GetCurrent()
{
	ComPtr<::Windows::UI::Xaml::IWindowStatics> pWindowStatics;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Window"), &pWindowStatics));

	ComPtr<::Windows::UI::Xaml::IWindow> pResult;
	api::CheckHR(pWindowStatics->get_Current(&pResult));

	return Import::Create<Window>(pResult.Get());
}		

void Window::Activate()
{
	api::CheckHR(GetCoreObj()->Activate());
}

void Window::Close()
{
	api::CheckHR(GetCoreObj()->Close());
}

void Window::SetContent(const winrt_ptr<Import::Object>& pNode)
{
	//move this to UIElement
	ComPtr<::Windows::UI::Xaml::IUIElement> pUIElement;
	api::CheckHR(pNode->GetCoreObj()->QueryInterface(__uuidof(IUIElement), &pUIElement));

	api::CheckHR(GetCoreObj()->put_Content(pUIElement.Get()));
}

}}}}