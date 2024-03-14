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
		//������
		//�����F�i�t�@�C���p�X�A�摜�̉����A�摜�̏c���A�����������j
		void Init(const char* Sprite , const float w , const float h , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(CountClass State , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(SymbolClass State , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(FrameClass State , const char* Sprite[] , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Init(PercentClass State , const char* Sprite1 , const char* Sprite2 , const float w = 1920.0f , const float h = 1080.0f , AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		//�X�V
		void Update()
		{M_Sprite.Update(Vector2({ M_Position.x - 960.0f , M_Position.y - 540.0f }) , M_Rotation , M_Scale , M_Pivot);}
		//�`��
		void Draw(RenderContext& rc);

	//���W�E��]�E�g��

		//���W�̐ݒ�
		void SetPosition(const Vector2& pos)
		{M_Position = pos;}

		//���W�̎擾
		const Vector2& GetPosition() const
		{return M_Position;}

		//��]�̐ݒ�
		void SetRotation(const Quaternion& rot)
		{M_Rotation = rot;}

		//��]�̎擾
		const Quaternion& GetRotation() const
		{return M_Rotation;}

		//�g�嗦�̐ݒ�
		void SetScale(const Vector3 scale)
		{M_Scale = scale;}

		//���W�̎擾
		const Vector3& GetScale() const
		{return M_Scale;}

		//�s�{�b�g�̐ݒ�
		void SetPivot(const Vector2& pivot)
		{M_Pivot = pivot;}

		//�s�{�b�g�̎擾
		const Vector2& GetPivot() const
		{return M_Pivot;}

		//��Z�J���[�̐ݒ�
		void SetMulColor(const Vector4& mulColor)
		{M_Sprite.SetMulColor(mulColor);}

		//��Z�J���[�̎擾
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
		//�X�v���C�g
		Sprite M_Sprite;
		SpriteInitData M_InitData;

		//���W�E��]�E�g��E���S
		Vector2 M_Position    = Vector2::Zero;
		Quaternion M_Rotation = Quaternion::Identity;
		Vector3 M_Scale       = Vector3::One;
		Vector2 M_Pivot       = Sprite::DEFAULT_PIVOT;

		int M_Count     = 0;
		int M_Frame     = 0;
		float M_Percent = 0.0f;
	};
}


