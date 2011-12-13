#include "Windows.UI.Xaml.Markup.i.h"
#include "generator-api.h"
#include <Windows.UI.Xaml-coretypes.h>

using namespace Microsoft::WRL;
using namespace Windows::UI::Xaml::Markup;

namespace Import {
namespace Windows { namespace UI { namespace Xaml { namespace Markup {

//------------------------------------------------------------------------------------------
// XamlReader
//------------------------------------------------------------------------------------------

IMPLEMENT_CORE_TYPE(XamlReader)

winrt_ptr<Import::Object> XamlReader::Load(const std::wstring& xaml)
{
	ComPtr<IXamlReaderStatics> pFactory;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Markup.XamlReader"), &pFactory));

	ComPtr<IInspectable> pContent;
	api::CheckHR(pFactory->Load(api::ProperHSTRING(xaml), &pContent));
	
	return Import::Create<Import::Object>(pContent.Get());
}

}}}}}