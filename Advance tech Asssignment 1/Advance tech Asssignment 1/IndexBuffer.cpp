#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(Graphics& gfx, const std::vector<unsigned short>& indices)
{
	D3D11_BUFFER_DESC ibd = {};
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER; // What to set the buffer up as
	ibd.Usage = D3D11_USAGE_DEFAULT; // What the buffer will be used for
	ibd.CPUAccessFlags = 0U; // Whether the CPU needs to access the buffer (it doesn't yet)
	ibd.MiscFlags = 0u; // 
	ibd.ByteWidth = static_cast<unsigned int>(indices.size() * sizeof(unsigned short)); // Size of the buffer in bytes
	ibd.StructureByteStride = sizeof(unsigned short); // Size of each index
	D3D11_SUBRESOURCE_DATA subresourceData = {};
	subresourceData.pSysMem = indices.data(); // Triangles to use
	gfx.GetDevice()->CreateBuffer(&ibd, &subresourceData, &pIndexBuffer);
}

void IndexBuffer::Bind(Graphics& gfx) noexcept
{
	gfx.GetContext()->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);
}