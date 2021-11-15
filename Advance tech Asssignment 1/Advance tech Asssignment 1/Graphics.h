#pragma once
#include "Win.h"
#include <d3d11.h>
#include <wrl.h>
#include <vector>
#include <memory>
#include <directXMath.h>

#include "Mouse.h"



class Graphics
{
public:
	Graphics(HWND hWnd);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics() = default; 
	void EndFrame();
	void ClearBuffer(float red, float green, float blue) noexcept;
	void DrawTestTriangle(float x, float y, float z);
	void DrawIndexed(UINT count) noexcept;
	void SetProjection(DirectX::FXMMATRIX proj) noexcept;
	DirectX::XMMATRIX GetProjection() const noexcept;
	void SetCamera(DirectX::FXMMATRIX cam) noexcept;
	DirectX::XMMATRIX GetCamera() const noexcept;

	Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwap;
	Microsoft::WRL::ComPtr <ID3D11DeviceContext> pContext;
	Microsoft::WRL::ComPtr <ID3D11RenderTargetView> pTarget;
	Microsoft::WRL::ComPtr <ID3D11DepthStencilView> pDSV;
	
private:
	DirectX::XMMATRIX projection;
	DirectX::XMMATRIX camera;
};
