#pragma once

#include "Object.h"

#include <Windows.Foundation.h>

namespace Windows { namespace Foundation {

	//Uri
	class Uri : public Object {
	public:
		DECLARE_DEFAULT_INTERFACE(ABI::Windows::Foundation::IUriRuntimeClass)

		Uri(const std::wstring& str);		
	};

}}