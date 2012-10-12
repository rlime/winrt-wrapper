#include "pch.h"
#include "Windows.UI.Xaml.Controls.e.h"
#include "Windows.UI.Xaml.Controls.h"

namespace Export {
namespace Windows { namespace UI { namespace Xaml { namespace Controls {

HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerEntered( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerEntered(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerPressed( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerPressed(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                
HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerMoved( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerMoved(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerReleased( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerReleased(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerExited( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerExited(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerCaptureLost( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerCaptureLost(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerCanceled( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerCanceled(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnPointerWheelChanged( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs *e)
{
	try {
		impl_->OnPointerWheelChanged(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnTapped( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs *e)
{
	try {
		impl_->OnTapped(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnDoubleTapped( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs *e)
{
	try {
		impl_->OnDoubleTapped(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnHolding( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs *e)
{
	try {
		impl_->OnHolding(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnRightTapped( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs *e)
{
	try {
		impl_->OnRightTapped(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnManipulationStarting( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs *e)
{
	try {
		impl_->OnManipulationStarting(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnManipulationInertiaStarting( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs *e)
{
	try {
		impl_->OnManipulationInertiaStarting(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnManipulationStarted( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs *e)
{
	try {
		impl_->OnManipulationStarted(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnManipulationDelta( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs *e)
{
	try {
		impl_->OnManipulationDelta(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnManipulationCompleted( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs *e)
{
	try {
		impl_->OnManipulationCompleted(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnKeyUp( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs *e)
{
	try {
		impl_->OnKeyUp(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnKeyDown( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs *e)
{
	try {
		impl_->OnKeyDown(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnGotFocus( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IRoutedEventArgs *e)
{
	try {
		impl_->OnGotFocus(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnLostFocus( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IRoutedEventArgs *e)
{
	try {
		impl_->OnLostFocus(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnDragEnter( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	try {
		impl_->OnDragEnter(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnDragLeave( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	try {
		impl_->OnDragLeave(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnDragOver( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	try {
		impl_->OnDragOver(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                            
HRESULT STDMETHODCALLTYPE ControlOverrides::OnDrop( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IDragEventArgs *e)
{
	try {
		impl_->OnDrop(e);
		return 0;
	}
	catch (...) {
		return -1;
	}	
}

                        
}}}}}