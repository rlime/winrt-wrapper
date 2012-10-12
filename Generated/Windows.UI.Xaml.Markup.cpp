#include "pch.h"
#include "Windows.UI.Xaml.Markup.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

using namespace ABI::Windows::UI::Xaml::Markup;

namespace Windows { namespace UI { namespace Xaml { namespace Markup {

//------------------------------------------------------------------------------------------
// XamlReader
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(XamlReader)

Object* XamlReader::Load(const std::wstring& xaml)
{
	ComPtr<IXamlReaderStatics> pFactory;
	api::CheckHR(::Windows::Foundation::GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Xaml.Markup.XamlReader"), &pFactory));

	ComPtr<IInspectable> pContent;
	api::CheckHR(pFactory->Load(api::ProperHSTRING(xaml), &pContent));
	
	return Create<Object>(pContent.Get());
}

}}}}