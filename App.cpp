#include "pch.h"

#include "App.h"
//#include "MainPage.h"
#include "Generated/Windows.UI.Xaml.Controls.h"
#include "Generated/Windows.Foundation.h"
#include "Generated/Windows.UI.Xaml.Markup.h"
#include "Generated/Windows.UI.Popups.h"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Markup;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Popups;

void App::OnLaunched(ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args)
{
	/*wchar_t const* xamlContent =
      L"<Grid xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\">"
      L"  <TextBlock Text=\"Hello, world\" />"
      L"</Grid>";*/
		
	const wchar_t* xamlContent =
		L"<Grid Background=\"#FF0C0C0C\" xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\" xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\">"
            L"<TextBox x:Name=\"Edit\" HorizontalAlignment=\"Left\" Margin=\"93,108,0,0\" Text=\"Josef\" VerticalAlignment=\"Top\"/>"
            L"<ComboBox HorizontalAlignment=\"Left\" Margin=\"93,167,0,0\" VerticalAlignment=\"Top\" Width=\"120\"/>"
            L"<CheckBox Content=\"CheckBox\" HorizontalAlignment=\"Left\" Margin=\"97,228,0,-1\" VerticalAlignment=\"Top\"/>"
            L"<Button x:Name=\"ChangeButton\" Content=\"Trhni si!\" HorizontalAlignment=\"Left\" Height=\"41\" Margin=\"93,278,0,0\" VerticalAlignment=\"Top\" Width=\"120\"/>"
        L"</Grid>";

	FrameworkElement* root = winrt_cast<FrameworkElement>(XamlReader::Load(xamlContent));		
	Window::GetCurrent()->SetContent(root);
	Window::GetCurrent()->Activate();

	Button* change_button = winrt_cast<Button>(root->FindName(L"ChangeButton"));	
	change_button->SetWidth(400);
	change_button->Click.connect(std::bind(&App::OnButton, this));
}

void App::OnButton()
{
	FrameworkElement* root = winrt_cast<FrameworkElement>(Window::GetCurrent()->GetContent());
	TextBox* edit = winrt_cast<TextBox>(root->FindName(L"Edit"));	
	edit->SetText(L"Cau " + edit->GetText());

	MessageDialog dlg(L"This is my messagebox", L"messagebox");
	dlg.ShowAsync();
}
