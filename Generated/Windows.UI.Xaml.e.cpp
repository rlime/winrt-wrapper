#include "Windows.UI.Xaml.e.h"
#include "Windows.UI.Xaml.i.h"

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

HRESULT ApplicationOverrides::OnInitialize()
{
	try {
		_impl->OnInitialize();
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT ApplicationOverrides::OnActivated(::Windows::ApplicationModel::Activation::IActivatedEventArgs *args)
{
	try {
		_impl->OnActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT ApplicationOverrides::OnLaunched(::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args)
{
	try {
		_impl->OnLaunched(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT ApplicationOverrides::OnFileActivated(::Windows::ApplicationModel::Activation::IFileActivatedEventArgs *args)
{
	try {
		_impl->OnFileActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT ApplicationOverrides::OnSearchActivated(::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs *args)
{
	try {
		_impl->OnSearchActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT ApplicationOverrides::OnSharingTargetActivated(::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs *args)
{
	try {
		_impl->OnSharingTargetActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

HRESULT ApplicationOverrides::OnFilePickerActivated(::Windows::ApplicationModel::Activation::IFilePickerActivatedEventArgs *args)
{
	try {
		_impl->OnFilePickerActivated(args);
		return 0;
	}
	catch (...) {
		return  -1;
	}
}

}}}}