#include <windef.h>
#include "generator-api.h"
#include "App.h"
#include "Generated/Windows.UI.Xaml.Controls.i.h"

using namespace Import::Windows::UI::Xaml::Controls;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	api::InitWinRT();

	winrt_ptr<App> app = new App();
	app->Run(); 

	return 0;
}