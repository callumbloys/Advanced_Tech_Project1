#pragma once
#include "Graphics.h"
#include <DirectXMath.h>
#include "Game.h"

class Camera
{
public:
	Camera() noexcept;
	DirectX::XMMATRIX GetMatrix() const noexcept;
	void SpawnControlWindow() noexcept;
	void Reset() noexcept;
	void Rotate(float dx, float dy) noexcept;
	void Translate(DirectX::XMFLOAT3 translation) noexcept;

private:
	DirectX::XMFLOAT3 pos;
	float pitch;
	float yaw;
	static constexpr float travelSpeed = 10.0f;
	static constexpr float rotationSpeed = 3.0f;
};