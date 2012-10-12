#pragma once

#include "Object.h"
#include <Windows.UI.Xaml.Markup.h>

namespace Windows { namespace UI { namespace Xaml { namespace Markup {

	//XamlReader
	class XamlReader : public Object {
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::UI::Xaml::Markup::IXamlReader)
		
		static Object* Load(const std::wstring&);		

	private:
		XamlReader();
	};

}}}}