#pragma once
#include "Graphics.h"
class Bindable
{
public:
	virtual void Bind(Graphics& gfx) = 0;
	virtual ~Bindable() = default;
protected:
	
};