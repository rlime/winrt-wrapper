#pragma once

#include "Generated/Windows.UI.Xaml.i.h"
#include "MainPage.h"

class App : public Import::Windows::UI::Xaml::Application
{
public:
	virtual void OnLaunched(Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args);

protected:
	winrt_ptr<MainPage> _main_page;
};
