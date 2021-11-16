#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(Graphics& gfx, const std::vector<Vertex>& vertices) : stride(sizeof(Vertex))
{
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.CPUAccessFlags = 0U;
	bufferDesc.MiscFlags = 0U;
	bufferDesc.ByteWidth = UINT(sizeof(Vertex) * vertices.size());
	bufferDesc.StructureByteStride = sizeof(Vertex);
	D3D11_SUBRESOURCE_DATA subresourceData = {};
	subresourceData.pSysMem = vertices.data();
	GetDevice(gfx)->CreateBuffer(&bufferDesc, &subresourceData, &pVertexBuffer);
}

void VertexBuffer::Bind(Graphics& gfx)
{
	const UINT offset = 0u;
	GetContext(gfx)->IASetVertexBuffers(
		0U,
		1U,
		pVertexBuffer.GetAddressOf(),
		&stride,
		&offset
	);
}