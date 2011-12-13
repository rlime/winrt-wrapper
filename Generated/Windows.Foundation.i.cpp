#include "Windows.Foundation.i.h"

using namespace Windows::Foundation;
using namespace Microsoft::WRL;

namespace Import {
namespace Windows { namespace Foundation {

//------------------------------------------------------------------------------------------
// Uri
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(Uri)

Uri::Uri(const std::wstring& uri)
{
	ComPtr<IUriRuntimeClassFactory> pFactory;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.Foundation.Uri"), &pFactory));
	
	ComPtr<CoreType_t> pUri;
	api::CheckHR(pFactory->CreateUri(api::ProperHSTRING(uri), &pUri));

	Attach(pUri.Get());
}

}}}