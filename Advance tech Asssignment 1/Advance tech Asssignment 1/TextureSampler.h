#pragma once
#include "Bindable.h"

class TextureSampler : public Bindable
{
public:
	TextureSampler(Graphics& gfx);
	void Bind(Graphics& gfx) noexcept override;
private:
	Microsoft::WRL::ComPtr<ID3D11SamplerState> sampler;
};