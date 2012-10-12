#pragma once

#include "Object.h"

#include <windows.ui.popups.h>

namespace Windows { namespace UI { namespace Popups {

class MessageDialog : public Object {
public:
	DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Popups::IMessageDialog)

	MessageDialog(const std::wstring& content);
	MessageDialog(const std::wstring& content, const std::wstring& title);
	void ShowAsync();
};

}}}