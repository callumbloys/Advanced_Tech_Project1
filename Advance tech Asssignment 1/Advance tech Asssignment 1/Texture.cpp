#include "Texture.h"
#include "TextureLoader.h"
Texture::Texture(Graphics& gfx, const std::wstring& filepath)
{
	auto result = DirectX::CreateWICTextureFromFile(gfx.GetDevice(), filepath.c_str(), NULL, &shaderResourceView);
	assert(SUCCEEDED(result));

}

void Texture::Bind(Graphics& gfx)
{
	gfx.GetContext()->PSSetShaderResources
	(
		0U,
		1U,
		shaderResourceView.GetAddressOf()
	);
}