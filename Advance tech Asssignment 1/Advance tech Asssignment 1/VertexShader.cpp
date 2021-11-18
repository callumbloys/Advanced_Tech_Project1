#include "VertexShader.h"

VertexShader::VertexShader(Graphics& gfx, const std::wstring& path, const std::vector<D3D11_INPUT_ELEMENT_DESC>& layout)
{
    D3DReadFileToBlob(path.c_str(), &pBytecodeBlob);
    gfx.GetDevice()->CreateInputLayout(
        layout.data(),
        static_cast<unsigned int>(layout.size()),
        pBytecodeBlob->GetBufferPointer(),
        pBytecodeBlob->GetBufferSize(),
        &pInputLayout
    );
    gfx.GetDevice()->CreateVertexShader(
        pBytecodeBlob->GetBufferPointer(),
        pBytecodeBlob->GetBufferSize(),
        nullptr,
        &pVertexShader
    );
}

void VertexShader::Bind(Graphics& gfx)
{
    gfx.GetContext()->IASetInputLayout(pInputLayout.Get());
    gfx.GetContext()->VSSetShader(pVertexShader.Get(), nullptr, 0u);
}