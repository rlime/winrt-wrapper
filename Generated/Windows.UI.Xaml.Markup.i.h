#pragma once

#include "Object.i.h"
#include <Windows.UI.Xaml-coretypes.h>

namespace Import {
namespace Windows { namespace UI { namespace Xaml { namespace Markup {

	//XamlReader
	class XamlReader : public Import::Object {
	public:
		DECLARE_CORE_TYPE(::Windows::UI::Xaml::Markup::IXamlReader)
		
		static winrt_ptr<Import::Object> Load(const std::wstring&);		

	private:
		XamlReader();
	};

}}}}}