#pragma once

#include "Generated/Windows.UI.Xaml.Controls.i.h"

class MainPage : public Import::Windows::UI::Xaml::Controls::UserControl
{
public:
	MainPage();
	
	void OnChangeButtonClick();
	void OnExitButtonClick();

private:
	winrt_ptr<Import::Windows::UI::Xaml::Controls::TextBox> _text_box;
};
