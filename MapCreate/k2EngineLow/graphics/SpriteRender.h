#pragma once
enum class CountClass
{
	COUNT0,
	COUNT1,
	COUNT2,
	COUNT3,
	COUNT4,
	COUNT5,
	COUNT6,
	COUNT7,
	COUNT8,
	COUNT9,
};
enum class SymbolClass
{
	COLON,
	PERCENT
};
enum class FrameClass
{
	FRAME15 = 15,
	FRAME30 = 30,
	FRAME45 = 45,
	FRAME60 = 60,
};
enum class PercentClass
{
	STATE0 = 0,
	STATE1 = 1,
	STATE2 = 2,
	STATE3 = 3,
	STATE4 = 4,
	STATE5 = 5,
};
namespace nsK2EngineLow
{
	class RenderingEngine;
	class SpriteRender : public IRender
	{
	public:
		//初期化
		//引数：（ファイルパス、画像の横幅、画像の縦幅、半透明合成）
		void Init(const char* Sprite , const float w , const float h , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(CountClass State , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(SymbolClass State , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(FrameClass State , const char* Sprite[] , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(PercentClass State , const char* Sprite1 , const char* Sprite2 , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		//更新
		void Update()
		{M_Sprite.Update(Vector2({ M_Position.x - 960.0f , M_Position.y - 540.0f }) , M_Rotation , M_Scale , M_Pivot);}
		//描画
		void Draw(RenderContext& rc);

	//座標・回転・拡大

		//座標の設定
		void SetPosition(const Vector2& pos)
		{M_Position = pos;}

		//座標の取得
		const Vector2& GetPosition() const
		{return M_Position;}

		//回転の設定
		void SetRotation(const Quaternion& rot)
		{M_Rotation = rot;}

		//回転の取得
		const Quaternion& GetRotation() const
		{return M_Rotation;}

		//拡大率の設定
		void SetScale(const Vector3 scale)
		{M_Scale = scale;}

		//座標の取得
		const Vector3& GetScale() const
		{return M_Scale;}

		//ピボットの設定
		void SetPivot(const Vector2& pivot)
		{M_Pivot = pivot;}

		//ピボットの取得
		const Vector2& GetPivot() const
		{return M_Pivot;}

		//乗算カラーの設定
		void SetMulColor(const Vector4& mulColor)
		{M_Sprite.SetMulColor(mulColor);}

		//乗算カラーの取得
		const Vector4& GetMulColor() const
		{return M_Sprite.GetMulColor();}

		void CountSet(int Count)
		{
			M_Count = Count;
		}
		void FrameSet(int Frame)
		{
			M_Frame = Frame;
		}
		void PercentSet(float Percent)
		{
			M_Percent = Percent;
		}

		void OnRender2D(RenderContext& rc) override;
	private:
		//スプライト
		Sprite M_Sprite;
		SpriteInitData M_InitData;

		//座標・回転・拡大・中心
		Vector2 M_Position    = Vector2::Zero;
		Quaternion M_Rotation = Quaternion::Identity;
		Vector3 M_Scale       = Vector3::One;
		Vector2 M_Pivot       = Sprite::DEFAULT_PIVOT;

		int M_Count     = 0;
		int M_Frame     = 0;
		float M_Percent = 0.0f;
	};
}


