#include "pch.h"

#include <cassert>
#include "Object.h"
#include "../generator-api.h"

/*
Object::Object() 
: inspectable_(nullptr), _ref_count(1) 
{}

Object::Object(IInspectable* core) 
: inspectable_(nullptr), _ref_count(1)
{
	Attach(core);	
}

Object::~Object() 
{
	int dbg = 0;
	if (inspectable_) {
		dbg = inspectable_->Release();
		inspectable_ = nullptr;
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
	assert(!inspectable_);
	inspectable_ = core;
	int dbg = 0;
	if (inspectable_) 
		dbg = inspectable_->AddRef();	
}
*/
