#include "pch.h"
#include "Windows.UI.Xaml.Controls.h"
#include "Windows.UI.Xaml.Controls.e.h"
#include "Windows.UI.Xaml.e.h"
#include <Windows.UI.Xaml.h>
#include <Windows.Foundation.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Foundation;

using namespace ABI::Windows::UI::Xaml::Controls;

namespace Windows { namespace UI { namespace Xaml { namespace Controls {

//------------------------------------------------------------------------------------------
// Control
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(Control)

Control::Control(IInspectable* core)
: FrameworkElement(core)
{
	GetDefaultInterface();
}

bool Control::IsEnabled()
{
	boolean b;
	api::CheckHR(GetDefaultInterface()->get_IsEnabled(&b));
	return b != 0;
}

void Control::SetIsEnabled(bool b)
{
	api::CheckHR(GetDefaultInterface()->put_IsEnabled(b));
}

HRESULT STDMETHODCALLTYPE Control::OnPointerEntered( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}

HRESULT STDMETHODCALLTYPE Control::OnPointerPressed( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnPointerMoved( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnPointerReleased( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnPointerExited( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnPointerCaptureLost( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnPointerCanceled( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnPointerWheelChanged( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnTapped( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnDoubleTapped( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnHolding( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnRightTapped( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnManipulationStarting( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnManipulationInertiaStarting( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnManipulationStarted( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnManipulationDelta( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnManipulationCompleted( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnKeyUp( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnKeyDown( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnGotFocus( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnLostFocus( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IRoutedEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnDragEnter( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnDragLeave( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnDragOver( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	return 0;
}
                            
HRESULT STDMETHODCALLTYPE Control::OnDrop( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	return 0;
}

//------------------------------------------------------------------------------------------
// UserControl
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(UserControl)

UserControl::UserControl() 
: Control(nullptr)
{
	/*
	ComPtr<IInspectable> pInsp;
	api::CheckHR(::Windows::Foundation::ActivateInstance(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Controls.UserControl"), &pInsp));
	
	Attach(pInsp.Get());	

	ComPtr<IUserControlFactory> pFactory;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Controls.UserControl"), &pFactory));
	
	ComPtr<IControlOverrides> pControlsOverrides = 
	move to Control
	_overrides = Make<Export::Windows::UI::Xaml::Controls::ControlOverrides>(this);
	
	ComPtr<IInspectable> pInner;
	api::CheckHR(pFactory->CreateInstance(
		nullptr, //something is wrong with: _overrides.Get(),
		&pInner,
		&_user_control
	));*/

	//ComPtr<IActivationFactory> activationFactory;
	ComPtr<IUserControlFactory> userControlFactory;
	api::CheckHR(GetActivationFactory(
		HString::MakeReference(L"Windows.UI.Xaml.Controls.UserControl").Get(),
		&userControlFactory
	));

	//ComPtr<IUserControlFactory> userControlFactory;
	//api::CheckHR(activationFactory.As(&userControlFactory));

	ComPtr<IInspectable> outer =
		Make<Export::Windows::UI::Xaml::Controls::ControlOverrides>(this);

	ComPtr<IInspectable> inner;
	ComPtr<DefaultInterface_t> userControl;
	api::CheckHR(userControlFactory->CreateInstance(
		outer.Get(),
		&inner, 
		&userControl
	));

	SetInspectable(inner);
}

UserControl::~UserControl()
{
	//crash upon exit without this:
	//DebugClearCore();
}

void UserControl::SetContent(const Object* pNode)
{
	//move this to UIElement
	ComPtr<ABI::Windows::UI::Xaml::IUIElement> pUIElement;
	api::CheckHR(pNode->GetInspectable()->QueryInterface(__uuidof(ABI::Windows::UI::Xaml::IUIElement), &pUIElement));

	api::CheckHR(GetDefaultInterface()->put_Content(pUIElement.Get()));
}

//------------------------------------------------------------------------------------------
// TextBox
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(TextBox)

TextBox::TextBox(IInspectable* core)
: Control(core)
{
}

std::wstring TextBox::GetText()
{
	api::ProperHSTRING hstr;
	api::CheckHR(GetDefaultInterface()->get_Text(&hstr));
	return hstr;
}

void TextBox::SetText(const std::wstring& text)
{
	api::CheckHR(GetDefaultInterface()->put_Text(api::ProperHSTRING(text)));
}

//------------------------------------------------------------------------------------------
// ButtonBase
//------------------------------------------------------------------------------------------

namespace Primitives {

IMPLEMENT_DEFAULT_INTERFACE(ButtonBase)

ButtonBase::ButtonBase() 
: Control(nullptr)
{
	ComPtr<DefaultInterface_t> pButton;
	api::CheckHR(::Windows::Foundation::ActivateInstance(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Controls.Button"), &pButton));

	SetInspectable(pButton);

	Click.init(this, &ButtonBase::RegisterClickHandler, &ButtonBase::UnregisterClickHandler);
}

ButtonBase::ButtonBase(IInspectable* core)
: Control(core)
{
	Click.init(this, &ButtonBase::RegisterClickHandler, &ButtonBase::UnregisterClickHandler);
}

EventRegistrationToken ButtonBase::RegisterClickHandler(
	Export::Windows::UI::Xaml::RoutedEventHandler* handler
)								
{
	EventRegistrationToken token;
	api::CheckHR(GetDefaultInterface()->add_Click(handler, &token));
	return token;
}

void ButtonBase::UnregisterClickHandler(EventRegistrationToken token)
{
	api::CheckHR(GetDefaultInterface()->remove_Click(token));
}

}

//------------------------------------------------------------------------------------------
// Button
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(Button)

Button::Button(IInspectable* core)
: ButtonBase(core)
{}

}}}}