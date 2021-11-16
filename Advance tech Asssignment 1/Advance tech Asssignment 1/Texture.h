#pragma once
#include "Bindable.h"
#include <string>

class Texture : public Bindable
{
public:
	Texture(Graphics& gfx, const std::wstring& filepath);
	void Bind(Graphics& gfx) override;
private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> shaderResourceView;
};