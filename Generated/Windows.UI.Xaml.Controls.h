#pragma once

#include "Windows.UI.Xaml.h"
#include "Windows.UI.Xaml.e.h"

#include <Windows.UI.Xaml.h>

namespace Windows { namespace UI { namespace Xaml { namespace Controls {

	//Control
	class Control : public Windows::UI::Xaml::FrameworkElement
	{
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::Controls::IControl)

		Control(IInspectable* core);

		bool IsEnabled();
		void SetIsEnabled(bool e);

		virtual HRESULT STDMETHODCALLTYPE OnPointerEntered( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerPressed( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerMoved( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerReleased( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerExited( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerCaptureLost( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerCanceled( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnPointerWheelChanged( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnTapped( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnDoubleTapped( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnHolding( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnRightTapped( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnManipulationStarting( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnManipulationInertiaStarting( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnManipulationStarted( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnManipulationDelta( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnManipulationCompleted( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnKeyUp( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnKeyDown( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnGotFocus( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnLostFocus( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IRoutedEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnDragEnter( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnDragLeave( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnDragOver( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e);
                            
        virtual HRESULT STDMETHODCALLTYPE OnDrop( 
            /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e);
	};

	//UserControl
	class UserControl : public Control
	{
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::Controls::IUserControl)

		UserControl();
		~UserControl();
		void SetContent(const Object* pNode);

	private:
		Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Controls::IControlOverrides> _overrides;
		Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Controls::IUserControl> _user_control;
	};

	//TextBox
	class TextBox : public Control
	{
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::Controls::ITextBox)

		TextBox(IInspectable* core);
		std::wstring GetText();
		void SetText(const std::wstring& text);
	};

	namespace Primitives {
	
		//ButtonBase
		class ButtonBase : public Control
		{
		public:
			DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase)

			ButtonBase();
			ButtonBase(IInspectable* core);				

		public:
			winrt_event<Export::Windows::UI::Xaml::RoutedEventHandler> Click;

		protected:
			EventRegistrationToken RegisterClickHandler(Export::Windows::UI::Xaml::RoutedEventHandler* handler);
			void UnregisterClickHandler(EventRegistrationToken token);
		};

	}

	//Button
	class Button : public Primitives::ButtonBase
	{
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::Controls::IButton)

		Button(IInspectable* core);
	};

}}}}