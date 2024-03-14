#include "k2EngineLowPreCompile.h"
#include "SpriteRender.h"
enum SymbolStorage
{
	SYMBOL_COLON,
	SYMBOL_PERCENT,
};
namespace nsK2EngineLow
{
	void SpriteRender::Init
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		M_InitData.m_fxFilePath = "Assets/shader/ColorOut.fx";
		M_InitData.m_vsEntryPointFunc = "VSMain";
		M_InitData.m_psEntryPoinFunc = "PSMain";
		
		M_InitData.m_ddsFilePath[0] = Sprite;

		M_InitData.m_width = static_cast<UINT>(w);
		M_InitData.m_height = static_cast<UINT>(h);

		M_InitData.m_alphaBlendMode = alphaBlendMode;

		M_Sprite.Init(M_InitData);
	}

	void SpriteRender::Init
	(
		CountClass State,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		M_InitData.m_fxFilePath = "Assets/shader/Count.fx";

		M_InitData.m_vsEntryPointFunc = "VSMain";
		M_InitData.m_psEntryPoinFunc = "PSMain";

		M_InitData.m_ddsFilePath[0] = "Assets/Sprite/Count2D/0.DDS";
		M_InitData.m_ddsFilePath[1] = "Assets/Sprite/Count2D/1.DDS";
		M_InitData.m_ddsFilePath[2] = "Assets/Sprite/Count2D/2.DDS";
		M_InitData.m_ddsFilePath[3] = "Assets/Sprite/Count2D/3.DDS";
		M_InitData.m_ddsFilePath[4] = "Assets/Sprite/Count2D/4.DDS";
		M_InitData.m_ddsFilePath[5] = "Assets/Sprite/Count2D/5.DDS";
		M_InitData.m_ddsFilePath[6] = "Assets/Sprite/Count2D/6.DDS";
		M_InitData.m_ddsFilePath[7] = "Assets/Sprite/Count2D/7.DDS";
		M_InitData.m_ddsFilePath[8] = "Assets/Sprite/Count2D/8.DDS";
		M_InitData.m_ddsFilePath[9] = "Assets/Sprite/Count2D/9.DDS";

		M_InitData.m_width = static_cast<UINT>(w);
		M_InitData.m_height = static_cast<UINT>(h);

		M_InitData.m_expandConstantBuffer = &M_Count;
		M_InitData.m_expandConstantBufferSize = sizeof(M_Count);

		M_InitData.m_alphaBlendMode = alphaBlendMode;

		M_Sprite.Init(M_InitData);
	}

	void SpriteRender::Init
	(
		SymbolClass State,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		M_InitData.m_fxFilePath = "Assets/shader/Symbol.fx";

		M_InitData.m_vsEntryPointFunc = "VSMain";
		M_InitData.m_psEntryPoinFunc = "PSMain";

		M_InitData.m_ddsFilePath[0] = "Assets/Sprite/Symbol2D/Colon.DDS";
		M_InitData.m_ddsFilePath[1] = "Assets/Sprite/Symbol2D/PerCent.DDS";

		M_InitData.m_width = static_cast<UINT>(w);
		M_InitData.m_height = static_cast<UINT>(h);

		int Symbol = static_cast<int>(State);
		M_InitData.m_expandConstantBuffer = &Symbol;
		M_InitData.m_expandConstantBufferSize = sizeof(Symbol);

		M_InitData.m_alphaBlendMode = alphaBlendMode;

		M_Sprite.Init(M_InitData);
	}

	void SpriteRender::Init
	(
		FrameClass State,
		const char* Sprite[],
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		M_InitData.m_fxFilePath = "Assets/shader/Animation.fx";
		M_InitData.m_vsEntryPointFunc = "VSMain";
		M_InitData.m_psEntryPoinFunc = "PSMain";

		for (int i = 0 ; i < static_cast<int>(State); i++)
		{M_InitData.m_ddsFilePath[i] = Sprite[i];}

		M_InitData.m_width = static_cast<UINT>(w);
		M_InitData.m_height = static_cast<UINT>(h);

		M_InitData.m_expandConstantBuffer = &M_Frame;
		M_InitData.m_expandConstantBufferSize = sizeof(&M_Frame);

		M_InitData.m_alphaBlendMode = alphaBlendMode;

		M_Sprite.Init(M_InitData);
	}

	void SpriteRender::Init
	(
		PercentClass State,
		const char* Sprite1,
		const char* Sprite2,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		M_InitData.m_fxFilePath = "Assets/shader/Percent.fx";
		M_InitData.m_vsEntryPointFunc = "VSMain";
		M_InitData.m_psEntryPoinFunc = "PSMain";

		M_InitData.m_ddsFilePath[0] = Sprite1;
		M_InitData.m_ddsFilePath[1] = Sprite2;

		M_InitData.m_width = static_cast<UINT>(w);
		M_InitData.m_height = static_cast<UINT>(h);

		int Percent = static_cast<int>(State);
		M_InitData.m_expandConstantBuffer = &M_Percent;
		M_InitData.m_expandConstantBufferSize = sizeof(&M_Percent);

		M_InitData.m_alphaBlendMode = alphaBlendMode;

		M_Sprite.Init(M_InitData);
	}

	void SpriteRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}
	
	void SpriteRender::OnRender2D(RenderContext& rc)
	{
		M_Sprite.Draw(rc);
	}
}

