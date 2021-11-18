#include "PixelShader.h"
#include <d3dcompiler.h>


PixelShader::PixelShader(Graphics& gfx, const std::wstring& path)
{
    Microsoft::WRL::ComPtr<ID3DBlob> blob;
    D3DReadFileToBlob(path.c_str(), &blob);
    gfx.GetDevice()->CreatePixelShader(
        blob->GetBufferPointer(),
        blob->GetBufferSize(),
        nullptr,
        &pPixelShader
    );
}

void PixelShader::Bind(Graphics& gfx)
{
    gfx.GetContext()->PSSetShader(
        pPixelShader.Get(),
        nullptr,
        0U
    );
}