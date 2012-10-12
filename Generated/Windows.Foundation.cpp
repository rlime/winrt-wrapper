#include "pch.h"
#include "Windows.Foundation.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Foundation;

namespace Windows { namespace Foundation {

//------------------------------------------------------------------------------------------
// Uri
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(Uri)

Uri::Uri(const std::wstring& arg)
{
	ComPtr<IActivationFactory> activationFactory;
	api::CheckHR(GetActivationFactory(
		HString::MakeReference(L"Windows.Foundation.Uri").Get(),
		&activationFactory
	));

	ComPtr<IUriRuntimeClassFactory> uriFactory;
	api::CheckHR(activationFactory.As(&uriFactory));

	ComPtr<DefaultInterface_t> uri;
	api::CheckHR(uriFactory->CreateUri(api::ProperHSTRING(arg), &uri));

	SetInspectable(uri);
}

}}