#include <cassert>
#include "Object.i.h"
#include "generator-api.h"

namespace Import {

Object::Object() 
: _core(nullptr), _ref_count(1) 
{}

Object::Object(IInspectable* core) 
: _core(nullptr), _ref_count(1)
{
	Attach(core);	
}

Object::~Object() 
{
	int dbg = 0;
	if (_core) {
		dbg = _core->Release();
		_core = nullptr;
	}
}

int Object::AddRef()
{
	++_ref_count;	
	return _ref_count;
}

int Object::Release()
{
	--_ref_count;
	
	if (!_ref_count) {
		delete this;
		return 0;
	}
	
	return _ref_count;
}

void Object::Attach(IInspectable* core)
{
	assert(!_core);
	_core = core;
	int dbg = 0;
	if (_core) dbg = _core->AddRef();	
}

}
