/*!
 * @brief	�X�v���C�g�p�̃V�F�[�_�[�B
 */

cbuffer cb : register(b0)
{
	float4x4 mvp;
	float4 mulColor;
};

struct VSInput
{
	float4 pos : POSITION;
	float2 uv  : TEXCOORD0;
};

struct PSInput
{
	float4 pos : SV_POSITION;
	float2 uv  : TEXCOORD0;
};

cbuffer PercentCb : register(b1)
{
	float Percent;
};

Texture2D<float4> PlayerTexture : register(t0);
Texture2D<float4> EnemyTexture : register(t1);
sampler Sampler : register(s0);

PSInput VSMain(VSInput In) 
{
	PSInput psIn;
	psIn.pos = mul( mvp, In.pos );
	psIn.uv = In.uv;
	return psIn;
}
float4 PSMain( PSInput In ) : SV_Target0
{
	float2 TexPercent = {1.0f - Percent , Percent};
	float4 TexColor1;
	float4 TexColor2;
	float4 TexFinal;

	float UpperLeftX;
	float UpperLeftY;
	float LowerRightX;
	float LowerRightY;

	TexColor1 = PlayerTexture.Sample(Sampler,In.uv);
	TexColor2 = EnemyTexture.Sample(Sampler,In.uv);

	TexColor1.rgb = pow(TexColor1.rgb, 1.0 / 2.2);
	TexColor2.rgb = pow(TexColor2.rgb, 1.0 / 2.2);
	
	if(In.uv.x <= TexPercent.x)
	{
		TexFinal = TexColor1;
	}else{
		TexFinal = TexColor2;
	}
	return TexFinal * mulColor;
}