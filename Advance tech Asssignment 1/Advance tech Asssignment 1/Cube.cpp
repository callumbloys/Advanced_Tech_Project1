#include "Cube.h"
#include "Bindable.h"
#include "BindableBase.h"
#include <memory>

Cube::Cube(Graphics& gfx, float sizeX, float sizeY, float sizeZ, float offsetX, float offsetY, float offsetZ) : transform(DirectX::XMMatrixTranslation(offsetX, offsetY, offsetZ)), pos(offsetX, offsetY, offsetZ)
{
    AddBind(std::make_unique<PixelShader>(gfx, L"PixelShader.cso"));
    AddBind(std::make_unique<VertexShader>(gfx, L"VertexShader.cso",
        std::vector<D3D11_INPUT_ELEMENT_DESC>{
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    }));
    AddBind(std::make_unique<VertexBuffer>(gfx, std::vector<Vertex>
    {
        { -sizeX, -sizeY, -sizeZ, 0.0F, 0.0F },
        { +sizeX, -sizeY, -sizeZ, 1.0F, 0.0F },
        { -sizeX, -sizeY, +sizeZ, 0.0F, 1.0F },
        { +sizeX, -sizeY, +sizeZ, 1.0F, 1.0F },
        { -sizeX, +sizeY, -sizeZ, 0.0F, 0.0F },
        { +sizeX, +sizeY, -sizeZ, 1.0F, 0.0F },
        { -sizeX, +sizeY, +sizeZ, 0.0F, 1.0F },
        { +sizeX, +sizeY, +sizeZ, 1.0F, 1.0F },
        { -sizeX, -sizeY, +sizeZ, 0.0F, 1.0F },
        { +sizeX, -sizeY, +sizeZ, 1.0F, 1.0F },
        { -sizeX, +sizeY, +sizeZ, 0.0F, 0.0F },
        { +sizeX, +sizeY, +sizeZ, 1.0F, 0.0F },
        { -sizeX, -sizeY, -sizeZ, 1.0F, 1.0F },
        { +sizeX, -sizeY, -sizeZ, 0.0F, 1.0F },
        { -sizeX, +sizeY, -sizeZ, 1.0F, 0.0F },
        { +sizeX, +sizeY, -sizeZ, 0.0F, 0.0F },
        { -sizeX, -sizeY, +sizeZ, 1.0F, 1.0F },
        { -sizeX, +sizeY, +sizeZ, 1.0F, 0.0F },
        { -sizeX, -sizeY, -sizeZ, 0.0F, 1.0F },
        { -sizeX, +sizeY, -sizeZ, 0.0F, 0.0F },
        { +sizeX, -sizeY, +sizeZ, 0.0F, 1.0F },
        { +sizeX, +sizeY, +sizeZ, 0.0F, 0.0F },
        { +sizeX, -sizeY, -sizeZ, 1.0F, 1.0F },
        { +sizeX, +sizeY, -sizeZ, 1.0F, 0.0F },
    }));
    AddBind(std::make_unique<IndexBuffer>(gfx, std::vector<unsigned short>{
        0, 2, 1, 2, 3, 1,
            4, 5, 6, 6, 5, 7,
            8, 10, 9, 9, 10, 11,
            12, 13, 14, 13, 15, 14,
            16, 18, 17, 17, 18, 19,
            20, 21, 22, 22, 21, 23
    }));
    AddBind(std::make_unique<Texture>(gfx, L"Wall.jpg"));
    AddBind(std::make_unique<TextureSampler>(gfx));
}

void Cube::Draw(Graphics& gfx)
{
    Drawable::Draw(gfx);
    SetModelMatrix(transform);
    GetContext(gfx)->DrawIndexed(36U, 0U, 0U);
}