#pragma once

#include "generator-api.h"
#include "Object.i.h"
#include "uriruntimeclass.h"

namespace Import {
namespace Windows { namespace Foundation {

	//Uri
	class Uri : public Import::Object {
	public:
		DECLARE_CORE_TYPE(::Windows::Foundation::IUriRuntimeClass)

		Uri(const std::wstring& str);		
	};

}}}