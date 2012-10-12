#include "pch.h"
#include "generator-api.h"
#include <winstring.h>
#include <roapi.h>

namespace api {

void InitWinRT()
{
	CheckHR(RoInitialize(RO_INIT_MULTITHREADED));
}

void CheckHR(HRESULT hr)
{
	if (hr) 
		throw "error";
}

//LiteralHSTRING
LiteralHSTRING::LiteralHSTRING(const wchar_t* str) 
{
	CheckHR(WindowsCreateStringReference(str, wcslen(str), &_header, &_hstring));
	//CheckHR(WindowsCreateString(str, wcslen(str), &_hstring));
}
	
LiteralHSTRING::~LiteralHSTRING()
{
	CheckHR(WindowsDeleteString(_hstring));
}

//ProperHSTRING
ProperHSTRING::ProperHSTRING()
	: _hstring(0)
{
}

ProperHSTRING::ProperHSTRING(const std::wstring& str) 
{
	CheckHR(WindowsCreateString(str.c_str(), wcslen(str.c_str()), &_hstring));
}
	
ProperHSTRING::~ProperHSTRING()
{
	Release();
}

void ProperHSTRING::Release()
{
	if (_hstring) {
		CheckHR(WindowsDeleteString(_hstring));
		_hstring = 0;
	}
}

ProperHSTRING::operator std::wstring () const
{
	UINT32 len;
	PCWSTR p = WindowsGetStringRawBuffer(_hstring, &len);
	return std::wstring(p, len);
}

HSTRING* ProperHSTRING::operator& ()
{
	Release();
	return &_hstring;
}

}

