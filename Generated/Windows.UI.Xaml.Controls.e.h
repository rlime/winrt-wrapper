#pragma once

#include "Generated/Object.i.h"
#include <Windows.UI.Xaml.h>
#include <Windows.UI.Xaml-coretypes.h>

namespace Import {
namespace Windows { namespace UI { namespace Xaml { namespace Controls {
	class UserControl;
}}}}}

namespace Export {
namespace Windows { namespace UI { namespace Xaml { namespace Controls {

	class ControlOverrides : 
		public Microsoft::WRL::RuntimeClass<::Windows::UI::Xaml::Controls::IControlOverrides>
	{
		InspectableClass(L"Export.Windows.UI.Xaml.Controls.ControlOverrides", TrustLevel::BaseTrust)
		Import::Windows::UI::Xaml::Controls::UserControl* _impl;

	public:
		ControlOverrides(Import::Windows::UI::Xaml::Controls::UserControl* impl) : _impl(impl) {}

		virtual HRESULT STDMETHODCALLTYPE OnPointerEntered( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerPressed( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerMoved( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerReleased( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerExited( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerCaptureLost( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerCanceled( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnPointerWheelChanged( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IPointerEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnTapped( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::ITappedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnDoubleTapped( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IDoubleTappedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnHolding( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IHoldingEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnRightTapped( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IRightTappedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnManipulationStarting( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IManipulationStartingEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnManipulationInertiaStarting( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IManipulationInertiaStartingEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnManipulationStarted( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IManipulationStartedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnManipulationDelta( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IManipulationDeltaEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnManipulationCompleted( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IManipulationCompletedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnKeyUp( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IKeyEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnKeyDown( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::Input::IKeyEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnGotFocus( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::IRoutedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnLostFocus( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::IRoutedEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnDragEnter( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::IDragEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnDragLeave( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::IDragEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnDragOver( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::IDragEventArgs *e);
                        
        virtual HRESULT STDMETHODCALLTYPE OnDrop( 
            /* [in] */ __RPC__in_opt ::Windows::UI::Xaml::IDragEventArgs *e);                      
	};


}}}}}