#pragma once

#include "Windows.UI.Xaml.i.h"
#include "Windows.UI.Xaml.e.h"
#include <Windows.UI.Xaml-coretypes.h>
#include <Windows.UI.Xaml.h>

namespace Import {
namespace Windows { namespace UI { namespace Xaml { namespace Controls {

	//Control
	class Control : public Import::Windows::UI::Xaml::FrameworkElement
	{
	public:
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::Controls::IControl)

		Control(IInspectable* core);
		bool IsEnabled();
		void SetIsEnabled(bool e);

		virtual void OnPointerEntered(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerPressed(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerMoved(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerReleased(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerExited(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerCaptureLost(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerCanceled(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnPointerWheelChanged(::Windows::UI::Xaml::Input::IPointerEventArgs *e);                        
        virtual void OnTapped(::Windows::UI::Xaml::Input::ITappedEventArgs *e);                        
        virtual void OnDoubleTapped(::Windows::UI::Xaml::Input::IDoubleTappedEventArgs *e);                        
        virtual void OnHolding(::Windows::UI::Xaml::Input::IHoldingEventArgs *e);                        
        virtual void OnRightTapped(::Windows::UI::Xaml::Input::IRightTappedEventArgs *e);                        
        virtual void OnManipulationStarting(::Windows::UI::Xaml::Input::IManipulationStartingEventArgs *e);                        
        virtual void OnManipulationInertiaStarting(::Windows::UI::Xaml::Input::IManipulationInertiaStartingEventArgs *e);                        
        virtual void OnManipulationStarted(::Windows::UI::Xaml::Input::IManipulationStartedEventArgs *e);                        
        virtual void OnManipulationDelta(::Windows::UI::Xaml::Input::IManipulationDeltaEventArgs *e);                        
        virtual void OnManipulationCompleted(::Windows::UI::Xaml::Input::IManipulationCompletedEventArgs *e);                        
        virtual void OnKeyUp(::Windows::UI::Xaml::Input::IKeyEventArgs *e);                        
        virtual void OnKeyDown(::Windows::UI::Xaml::Input::IKeyEventArgs *e);                        
        virtual void OnGotFocus(::Windows::UI::Xaml::IRoutedEventArgs *e);                        
        virtual void OnLostFocus(::Windows::UI::Xaml::IRoutedEventArgs *e);                        
        virtual void OnDragEnter(::Windows::UI::Xaml::IDragEventArgs *e);                        
        virtual void OnDragLeave(::Windows::UI::Xaml::IDragEventArgs *e);                        
        virtual void OnDragOver(::Windows::UI::Xaml::IDragEventArgs *e);                        
        virtual void OnDrop(::Windows::UI::Xaml::IDragEventArgs *e);
	};

	//UserControl
	class UserControl : public Control
	{
	public:
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::Controls::IUserControl)

		UserControl();
		~UserControl();
		void SetContent(const winrt_ptr<Import::Object>& pNode);

	private:
		Microsoft::WRL::ComPtr<::Windows::UI::Xaml::Controls::IControlOverrides> _overrides;
		Microsoft::WRL::ComPtr<::Windows::UI::Xaml::Controls::IUserControl> _user_control;
	};

	//TextBox
	class TextBox : public Control
	{
	public:
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::Controls::ITextBox)

		TextBox(IInspectable* core);
		std::wstring GetText();
		void SetText(const std::wstring& text);
	};

	namespace Primitives {
	
		//ButtonBase
		class ButtonBase : public Control
		{
		public:
			DECLARE_CORE_TYPE(::Windows::UI::Xaml::Controls::Primitives::IButtonBase)

			ButtonBase();
			ButtonBase(IInspectable* core);				

		public:
			winrt_event<
				Export::Windows::UI::Xaml::RoutedEventHandler::FuncType_t,
				ButtonBase
			> Click;

		protected:
			EventRegistrationToken AddClickHandler(Export::Windows::UI::Xaml::RoutedEventHandler::Callback_t clb);
			void RemoveClickHandler(EventRegistrationToken token);
		};

	}

	//Button
	class Button : public Primitives::ButtonBase
	{
	public:
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::Controls::IButton)

		Button(IInspectable* core);
	};

}}}}}