#include "pch.h"
#include "Windows.UI.Popups.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Foundation;

using namespace ABI::Windows::UI::Popups;

namespace Windows { namespace UI { namespace Popups {

//------------------------------------------------------------------------------------------
// MessageDialog
//------------------------------------------------------------------------------------------

IMPLEMENT_DEFAULT_INTERFACE(MessageDialog)

MessageDialog::MessageDialog(const std::wstring& content)
{
	ComPtr<IMessageDialogFactory> pFactory;
	api::CheckHR(GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Popups.MessageDialog"), &pFactory));
	
	ComPtr<DefaultInterface_t> pMessageDialog;
	api::CheckHR(pFactory->Create(
		api::ProperHSTRING(content), &pMessageDialog));

	SetInspectable(pMessageDialog);
}

MessageDialog::MessageDialog(const std::wstring& content, const std::wstring& title)
{
	ComPtr<IMessageDialogFactory> pFactory;
	api::CheckHR(GetActivationFactory(
		api::LiteralHSTRING(L"Windows.UI.Popups.MessageDialog"), &pFactory));
	
	ComPtr<DefaultInterface_t> pMessageDialog;
	api::CheckHR(pFactory->CreateWithTitle(
		api::ProperHSTRING(content), api::ProperHSTRING(title), &pMessageDialog));

	SetInspectable(pMessageDialog);
}

void MessageDialog::ShowAsync()
{
	ComPtr<ABI::Windows::Foundation::IAsyncOperation<IUICommand*>> pOperation;
	api::CheckHR(GetDefaultInterface()->ShowAsync(&pOperation));
}

}}}