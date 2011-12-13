#include "Windows.UI.Xaml.Controls.i.h"
#include "Windows.UI.Xaml.Controls.e.h"
#include "Windows.UI.Xaml.e.h"
#include <Windows.UI.Xaml.h>
#include <Windows.Foundation.h>

using namespace Microsoft::WRL;
using namespace Windows::UI::Xaml::Controls;

namespace Import {
namespace Windows { namespace UI { namespace Xaml { namespace Controls {

//------------------------------------------------------------------------------------------
// Control
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(Control)

Control::Control(IInspectable* core)
: FrameworkElement(core)
{
}

bool Control::IsEnabled()
{
	boolean b;
	api::CheckHR(GetCoreObj()->get_IsEnabled(&b));
	return b;
}

void Control::SetIsEnabled(bool b)
{
	api::CheckHR(GetCoreObj()->put_IsEnabled(b));
}

void Control::OnPointerEntered(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerEntered(e));
}                        
void Control::OnPointerPressed(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerPressed(e));
}                        
void Control::OnPointerMoved(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerMoved(e));
}                        
void Control::OnPointerReleased(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerReleased(e));
}                        
void Control::OnPointerExited(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerExited(e));
}                        
void Control::OnPointerCaptureLost(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerCaptureLost(e));
}                        
void Control::OnPointerCanceled(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerCanceled(e));
}                        
void Control::OnPointerWheelChanged(::Windows::UI::Xaml::Input::IPointerEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnPointerWheelChanged(e));
}                        
void Control::OnTapped(::Windows::UI::Xaml::Input::ITappedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnTapped(e));
}                        
void Control::OnDoubleTapped(::Windows::UI::Xaml::Input::IDoubleTappedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnDoubleTapped(e));
}                        
void Control::OnHolding(::Windows::UI::Xaml::Input::IHoldingEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnHolding(e));
}                        
void Control::OnRightTapped(::Windows::UI::Xaml::Input::IRightTappedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnRightTapped(e));
}                        
void Control::OnManipulationStarting(::Windows::UI::Xaml::Input::IManipulationStartingEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnManipulationStarting(e));
}                        
void Control::OnManipulationInertiaStarting(::Windows::UI::Xaml::Input::IManipulationInertiaStartingEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnManipulationInertiaStarting(e));
}                        
void Control::OnManipulationStarted(::Windows::UI::Xaml::Input::IManipulationStartedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnManipulationStarted(e));
}                        
void Control::OnManipulationDelta(::Windows::UI::Xaml::Input::IManipulationDeltaEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnManipulationDelta(e));
}                        
void Control::OnManipulationCompleted(::Windows::UI::Xaml::Input::IManipulationCompletedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnManipulationCompleted(e));
}                        
void Control::OnKeyUp(::Windows::UI::Xaml::Input::IKeyEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnKeyUp(e));
}                        
void Control::OnKeyDown(::Windows::UI::Xaml::Input::IKeyEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnKeyDown(e));
}                        
void Control::OnGotFocus(::Windows::UI::Xaml::IRoutedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnGotFocus(e));
}                        
void Control::OnLostFocus(::Windows::UI::Xaml::IRoutedEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnLostFocus(e));
}                        
void Control::OnDragEnter(::Windows::UI::Xaml::IDragEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnDragEnter(e));
}                        
void Control::OnDragLeave(::Windows::UI::Xaml::IDragEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnDragLeave(e));
}                        
void Control::OnDragOver(::Windows::UI::Xaml::IDragEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnDragOver(e));
}                        
void Control::OnDrop(::Windows::UI::Xaml::IDragEventArgs *e)
{
	ComPtr<IControlOverrides> pControlOverrides;
	api::CheckHR(Object::GetCoreObj()->QueryInterface(__uuidof(IControlOverrides), &pControlOverrides));
	api::CheckHR(pControlOverrides->OnDrop(e));
}

//------------------------------------------------------------------------------------------
// UserControl
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(UserControl)

UserControl::UserControl() 
: Control(nullptr)
{
	/*
	ComPtr<IInspectable> pInsp;
	api::CheckHR(::Windows::Foundation::ActivateInstance(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Controls.UserControl"), &pInsp));
	
	Attach(pInsp.Get());
	*/

	ComPtr<IUserControlFactory> pFactory;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Controls.UserControl"), &pFactory));
	
	//ComPtr<IControlOverrides> pControlsOverrides = 
	//move to Control
	_overrides = Make<Export::Windows::UI::Xaml::Controls::ControlOverrides>(this);
	
	ComPtr<IInspectable> pInner;
	api::CheckHR(pFactory->CreateInstance(
		nullptr, //something is wrong with: _overrides.Get(),
		&pInner,
		&_user_control
	));

	Attach(pInner.Get());
}

UserControl::~UserControl()
{
	//crash upon exit without this:
	DebugClearCore();
}

void UserControl::SetContent(const winrt_ptr<Import::Object>& pNode)
{
	//move this to UIElement
	ComPtr<::Windows::UI::Xaml::IUIElement> pUIElement;
	api::CheckHR(pNode->GetCoreObj()->QueryInterface(__uuidof(::Windows::UI::Xaml::IUIElement), &pUIElement));

	api::CheckHR(GetCoreObj()->put_Content(pUIElement.Get()));
}

//------------------------------------------------------------------------------------------
// TextBox
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(TextBox)

TextBox::TextBox(IInspectable* core)
: Control(core)
{
}

std::wstring TextBox::GetText()
{
	api::ProperHSTRING hstr;
	api::CheckHR(GetCoreObj()->get_Text(&hstr));
	return hstr;
}

void TextBox::SetText(const std::wstring& text)
{
	api::CheckHR(GetCoreObj()->put_Text(api::ProperHSTRING(text)));
}

//------------------------------------------------------------------------------------------
// ButtonBase
//------------------------------------------------------------------------------------------

namespace Primitives {

IMPLEMENT_CORE_TYPE(ButtonBase)

ButtonBase::ButtonBase() 
: Control(nullptr)
{
	ComPtr<CoreType_t> pButton;
	api::CheckHR(::Windows::Foundation::ActivateInstance(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Controls.Button"), &pButton));

	Attach(pButton.Get());

	Click.init(this, &ButtonBase::AddClickHandler, &ButtonBase::RemoveClickHandler);
}

ButtonBase::ButtonBase(IInspectable* core)
: Control(core)
{
	Click.init(this, &ButtonBase::AddClickHandler, &ButtonBase::RemoveClickHandler);
}

EventRegistrationToken ButtonBase::AddClickHandler(Export::Windows::UI::Xaml::RoutedEventHandler::Callback_t clb)
{
	ComPtr<Export::Windows::UI::Xaml::RoutedEventHandler> pHandler =
		Make<Export::Windows::UI::Xaml::RoutedEventHandler>(clb);
	
	EventRegistrationToken token;
	api::CheckHR(GetCoreObj()->add_Click(pHandler.Get(), &token));
	return token;
}

void ButtonBase::RemoveClickHandler(EventRegistrationToken token)
{
	api::CheckHR(GetCoreObj()->remove_Click(token));
}

}

//------------------------------------------------------------------------------------------
// Button
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(Button)

Button::Button(IInspectable* core)
: ButtonBase(core)
{}

}}}}}