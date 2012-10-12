#pragma once

#include "Generated/Windows.UI.Xaml.h"

class App : public Windows::UI::Xaml::Application
{
public:
	virtual void OnLaunched(ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs *args);
		
protected:
	void OnButton();
};
