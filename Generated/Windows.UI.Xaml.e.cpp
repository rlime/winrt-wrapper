#include "pch.h"
#include "Windows.UI.Xaml.e.h"
#include "Windows.UI.Xaml.h"

namespace Export {
namespace Windows { namespace UI { namespace Xaml {

/*void ApplicationOverrides::AddRef()
{
	int count = IApplicationOverrides::AddRef();
}

void ApplicationOverrides::Release()
{
	int count = IApplicationOverrides::Release();
}*/

//------------------------------------------------------------------------------------------
// ApplicationOverrides
//------------------------------------------------------------------------------------------


HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs *args)
{
	try {
		impl_->OnActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnLaunched( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args)
{
	try {
		impl_->OnLaunched(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnFileActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args)
{
	try {
		impl_->OnFileActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnSearchActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args)
{
	try {
		impl_->OnSearchActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnShareTargetActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args)
{
	try {
		impl_->OnShareTargetActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnFileOpenPickerActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs *args)
{
	try {
		impl_->OnFileOpenPickerActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnFileSavePickerActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs *args)
{
	try {
		impl_->OnFileSavePickerActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnCachedFileUpdaterActivated( 
    /* [in] */ __RPC__in_opt ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs *args)
{
	try {
		impl_->OnCachedFileUpdaterActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT STDMETHODCALLTYPE ApplicationOverrides::OnWindowCreated( 
    /* [in] */ __RPC__in_opt ABI::Windows::UI::Xaml::IWindowCreatedEventArgs *args)
{
	try {
		impl_->OnWindowCreated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}          

//------------------------------------------------------------------------------------------
// RoutedEventHandler
//------------------------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE RoutedEventHandler::Invoke(IInspectable* sender, ABI::Windows::UI::Xaml::IRoutedEventArgs* args)
{
	try {
		Object* pSender = Create<Object>(sender);
				
		::Windows::UI::Xaml::RoutedEventArgs Args(args);

		for (Callback_t& clb : handlers_) 
			clb(pSender, &Args);
		return 0;
	}
	catch (...) {
		return -1;
	}
}

}}}}