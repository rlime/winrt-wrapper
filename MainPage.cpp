#include "MainPage.h"
#include "Generated/Windows.UI.Xaml.i.h"
#include "Generated/Windows.UI.Xaml.Markup.i.h"

using namespace Import::Windows::UI::Xaml;
using namespace Import::Windows::Foundation;
using namespace Import::Windows::UI::Xaml::Markup;
using namespace Import::Windows::UI::Xaml::Controls;

MainPage::MainPage()
{
	const wchar_t* xamlContent =
	L"<Grid "
		L"xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\" "
		L"xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\" "    
		L"x:Name=\"LayoutRoot\" Background=\"#FF0C0C0C\"> "
        L"<TextBox x:Name=\"TextBox\" HorizontalAlignment=\"Left\" Margin=\"507,231,0,0\" Text=\"Write your name here\" VerticalAlignment=\"Top\"/> "
		L"<Button x:Name=\"ChangeButton\" Content=\"Say Hello\" HorizontalAlignment=\"Left\" Height=\"41\" Margin=\"507,278,0,0\" VerticalAlignment=\"Top\" Width=\"120\"/>"
		L"<Button x:Name=\"ExitButton\" Content=\"Exit\" HorizontalAlignment=\"Left\" Height=\"41\" Margin=\"507,350,0,0\" VerticalAlignment=\"Top\" Width=\"120\"/>"
    L"</Grid>";

	winrt_ptr<FrameworkElement> root = winrt_cast<FrameworkElement>(XamlReader::Load(xamlContent));		
	SetContent(root);

	winrt_ptr<Button> change_button = winrt_cast<Button>(root->FindName(L"ChangeButton"));	
	change_button->Click.connect(std::bind(&MainPage::OnChangeButtonClick, this));

	winrt_ptr<Button> exit_button = winrt_cast<Button>(root->FindName(L"ExitButton"));	
	exit_button->Click.connect(std::bind(&MainPage::OnExitButtonClick, this));
	exit_button->SetIsEnabled(false);

	_text_box = winrt_cast<TextBox>(root->FindName(L"TextBox"));
}

void MainPage::OnChangeButtonClick()
{
	_text_box->SetText(L"Hello " + _text_box->GetText() + L"!");
}

void MainPage::OnExitButtonClick()
{
	Window::GetCurrent()->Close();
}
