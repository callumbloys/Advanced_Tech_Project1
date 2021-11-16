#pragma once
#include "Drawable.h"
#include "Bindable.h"
class Cube : public Drawable
{
public:
	Cube(Graphics& gfx, float sizeX, float sizeY, float sizeZ, float offsetX = 0.0F, float offsetY = 0.0F, float offsetZ = 0.0F);
	//void Draw(Graphics& gfx);
	void Draw(Graphics& gfx) override;
	DirectX::XMMATRIX transform = DirectX::XMMatrixIdentity();
	DirectX::XMFLOAT3 pos;
};