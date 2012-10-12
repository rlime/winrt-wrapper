#ifndef GENERATOR_API_H
#define GENERATOR_API_H

#include <string>
#include <wrl/wrappers/corewrappers.h>


namespace api {

void CheckHR(HRESULT hr);

//LiteralHSTRING
class LiteralHSTRING {
public:
	LiteralHSTRING(const wchar_t* str);
	~LiteralHSTRING() ;
	operator HSTRING () const { return _hstring; }

private:
	HSTRING _hstring;
	HSTRING_HEADER _header;	
};

//ProperHSTRING
class ProperHSTRING {
public:
	ProperHSTRING();
	ProperHSTRING(const std::wstring& str);
	~ProperHSTRING();
	operator HSTRING () const { return _hstring; }
	operator std::wstring() const;
	HSTRING* operator& ();

private:
	void Release();

	HSTRING _hstring;
};

}



#endif