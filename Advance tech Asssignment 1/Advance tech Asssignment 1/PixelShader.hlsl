
struct PixelShaderInput
{
    float4 pos : SV_POSITION;
    float2 tex : TEXCOORD;
};

Texture2D tex;
SamplerState splr;

float4 main(PixelShaderInput input) : SV_TARGET
{
    // Draw the entire triangle yellow.
    //return float4(input.pos.x, input.pos.y, 0.0f, 1.0f);
    return tex.Sample(splr, input.tex);
}