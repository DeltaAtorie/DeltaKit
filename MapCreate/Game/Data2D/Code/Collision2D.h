#pragma once
struct SquareData
{
	char ObjectName[256]            = "nullptr";//�I�u�W�F�N�g�̖��O
	char Tag[256]                   = "nullptr";//�I�u�W�F�N�g�̃^�O
	float UpperLeftVertexX          = 0.0f;//��`�̍���X
	float UpperLeftVertexY          = 0.0f;//��`�̍���Y
	float LowerRightVertexX         = 0.0f;//��`�̉E��X
	float LowerRightVertexY         = 0.0f;//��`�̉E��Y
	float Wide                      = 0.0f;
	float Height                    = 0.0f;
};
struct CircleData
{
	char ObjectName[256] = "nullptr";//�I�u�W�F�N�g�̖��O
	char Tag[256]        = "nullptr";//�I�u�W�F�N�g�̃^�O
	float CircleX        = 0.0f;//�P�ʉ~��X���W
	float CircleY        = 0.0f;//�P�ʉ~��Y���W
	float CenterX        = 0.0f;//�~�̒��S��X���W
	float CenterY        = 0.0f;//�~�̒��S��Y���W
	float Radius         = 0.0f;//�~�̔��a
	float Angle          = 0.0f;//�p�x
	float Radian         = 0.0f;//���W�A���p�x
};
enum class SquareDirection
{
	NON   = 0,
	UP    = 1,
	RIGHT = 2,
	DOWN  = 3,
	LEFT  = 4
};
enum class CrashType
{
	EtoE,//��E��
	BtoB,//�{�́E�{��
	BtoE//�{�́E��
};
class Collision2D : public IGameObject
{
public:
//����̐���
	void SquareDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag);
	void CircleDataSet(float Radius , float CenterX , float CenterY , const char* ObjectName , const char* Tag);
//����̕���
	//�{��
	bool CopyBodyData(SquareData& Decision   , const char* ObjectName);
	bool CopyBodyData(CircleData& Decision   , const char* ObjectName);

	//�y�^�O���t���������̖{�́z�̃R�s�[
	bool CopyBodysData(SquareData& Decision , const char* Tag , int Count);
	bool CopyBodysData(CircleData& Decision , const char* Tag , int Count);

	//��
	bool CopyEmptyData(SquareData& Decision  , const char* ObjectName , SquareDirection Direction);

	//�y�^�O���t���������̋�z�̃R�s�[
	bool CopyEmptysData(SquareData& Decision , const char* Tag        , SquareDirection Direction , int Count);

//����̍X�V
	void SquareSetPosition(float PositionX , float PositionY , const char* ObjectName)
	{
		for (int Count = 0 ; Count < 2048; Count++)
		{
			if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
			{
				Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX = (PositionX - (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY = (PositionY + (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX = (PositionX + (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY = (PositionY - (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));

				BodyUpSetPosition(Count);
				BodyRightSetPosition(Count);
				BodyLeftSetPosition(Count);
				BodyDownSetPosition(Count);
				return;
			}
		}
	}
	void CircleSetPosition(float PositionX, float PositionY, const char* ObjectName)
	{
		for (int Count = 0; Count < 2048; Count++)
		{
			if (strcmp(Circle[Count].ObjectName, ObjectName) == 0)
			{
				Circle[Count].CenterX = PositionX;
				Circle[Count].CenterY = PositionY;
				return;
			}
		}
	}

//����̏Փ�
	bool SquareAndSquare(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2 , CrashType Type);
	bool SquareAndSquare(const char* ObjectName1 , const char* ObjectName2 , CrashType Type);
	bool SquareAndSquare(const char* ObjectName1 , const char* ObjectName2 , SquareDirection Direction2 , CrashType Type);

	bool CircleAndCircle(const char* ObjectName1 , const char* ObjectName2 , CrashType Type);

	bool SquareAndCircle(CrashType Type);
private:
	void BodyInSideDataSet(int Count)
	{
		for (int Direction = static_cast<int>(SquareDirection::UP) ; Direction <= static_cast<int>(SquareDirection::LEFT) ; Direction++)
		{
			strcpy(Square[Count][static_cast<int>(Direction)].ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
			strcpy(Square[Count][static_cast<int>(Direction)].Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
		}

		BodyUpSetPosition(Count);
		BodyRightSetPosition(Count);
		BodyDownSetPosition(Count);
		BodyLeftSetPosition(Count);
	}
	void BodyUpSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexY  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY);
		Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
	}
	void BodyRightSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexX = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
	}
	void BodyDownSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexY = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY);
	}
	void BodyLeftSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexX  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
	}
private:
	SquareData Square[2048][5];
	CircleData Circle[2048];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;
};
