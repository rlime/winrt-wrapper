#pragma once

#include "Generated/Object.h"
#include <Windows.UI.Xaml.Controls.h>

namespace Windows { namespace UI { namespace Xaml { namespace Controls {
	class UserControl;
}}}}

namespace Export {
namespace Windows { namespace UI { namespace Xaml { namespace Controls {

	class ControlOverrides : 
		public Microsoft::WRL::RuntimeClass<ABI::Windows::UI::Xaml::Controls::IControlOverrides>
	{
		InspectableClass(L"Export.Windows.UI.Xaml.Controls.ControlOverrides", TrustLevel::BaseTrust)

	public:
		ControlOverrides(::Windows::UI::Xaml::Controls::UserControl* impl) : impl_(impl) {}

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

	private:
		::Windows::UI::Xaml::Controls::UserControl* impl_;
	};


}}}}}