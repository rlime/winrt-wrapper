#include "App.h"
#include "MainPage.h"
#include "Generated/Windows.Foundation.i.h"
#include "Generated/Windows.UI.Xaml.Markup.i.h"

using namespace Import::Windows::UI::Xaml;
using namespace Import::Windows::UI::Xaml::Markup;

void App::OnLaunched(Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args)
{
	/*wchar_t const* xamlContent =
      L"<Grid xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\">"
      L"  <TextBlock Text=\"Hello, world\" />"
      L"</Grid>";*/
	
	/*
	const wchar_t* xamlContent =
		L"<Grid Background=\"#FF0C0C0C\" xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\">"
            L"<TextBox HorizontalAlignment=\"Left\" Margin=\"93,108,0,0\" Text=\"Josef\" VerticalAlignment=\"Top\"/>"
            L"<ComboBox HorizontalAlignment=\"Left\" Margin=\"93,167,0,0\" VerticalAlignment=\"Top\" Width=\"120\"/>"
            L"<CheckBox Content=\"CheckBox\" HorizontalAlignment=\"Left\" Margin=\"97,228,0,-1\" VerticalAlignment=\"Top\"/>"
            L"<Button Content=\"Trhni si!\" HorizontalAlignment=\"Left\" Height=\"41\" Margin=\"93,278,0,0\" VerticalAlignment=\"Top\" Width=\"120\"/>"
        L"</Grid>";

	Window::GetCurrent()->SetContent(XamlReader::Load(xamlContent));
	//Window::GetCurrent()->Activate();*/

	/*winrt_ptr<MainPage>*/ _main_page = new MainPage(); //lok promenna ok exit
	Window::GetCurrent()->SetContent(_main_page);
    Window::GetCurrent()->Activate();
	
	//_main_page.~winrt_ptr(); //ok

	/* ok in arbitrary order:
	_main_page.~winrt_ptr();
	int vo = Object::GetCoreObj()->Release();
	-> delete is a problem
	*/
	
	/* still ok, ~ComPtrs are needed before b
	int a = _main_page->Object::GetCoreObj()->Release();
	delete _main_page.get();

	_overrides.~ComPtr();
	_application.~ComPtr();
	int b = Object::GetCoreObj()->Release();
	delete this;*/
}
