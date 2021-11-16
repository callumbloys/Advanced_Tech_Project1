#pragma once
#include "Bindable.h"
#include "Vertex.h"
#include "Graphics.h"

class VertexBuffer : public Bindable
{
public:
	VertexBuffer(Graphics& gfx, const std::vector<Vertex>& vertices);
	void Bind(Graphics& gfx) override;
protected:
	Microsoft::WRL::ComPtr<ID3D11Buffer> pVertexBuffer;
	UINT stride;
};