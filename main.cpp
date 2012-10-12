#include "pch.h"
#include "App.h"

using namespace Microsoft::WRL::Wrappers;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int wmain()
{
	RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
	if (FAILED(initialize)) return 1;

	new App();
	App::Start();

	return 0;
}
