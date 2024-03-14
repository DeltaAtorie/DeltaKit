#pragma once
struct SquareData
{
	char ObjectName[256]            = "nullptr";//オブジェクトの名前
	char Tag[256]                   = "nullptr";//オブジェクトのタグ
	Vector2 UpperLeftVertex         = { 0.0f , 0.0f };//矩形の左上
	Vector2 LowerRightVertex        = { 0.0f , 0.0f };//矩形の右下
	float Wide                      = 0.0f;
	float Height                    = 0.0f;
};
struct CircleData
{
	char ObjectName[256] = "nullptr";//オブジェクトの名前
	char Tag[256]        = "nullptr";//オブジェクトのタグ
	Vector2 Circle       = { 0.0f , 0.0f };
	Vector2 Center       = { 0.0f , 0.0f };
	float Radius         = 0.0f;//円の半径
	float Angle          = 0.0f;//角度
	float Radian         = 0.0f;//ラジアン角度
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
	EtoE,//空・空
	BtoB,//本体・本体
	BtoE//本体・空
};
class Collision2D : public IGameObject
{
public:
//判定の生成
	void SquareDataSet(float  Wide , float Height , Vector2 Position , const char* ObjectName , const char* Tag);
	void CircleDataSet(float Radius , Vector2 Position, const char* ObjectName , const char* Tag);
//判定の複製
	//本体
	bool CopyBodyData(SquareData& Decision   , const char* ObjectName);
	bool CopyBodyData(CircleData& Decision   , const char* ObjectName);

	//【タグが付いた複数の本体】のコピー
	bool CopyBodysData(SquareData& Decision , const char* Tag , int Count);
	bool CopyBodysData(CircleData& Decision , const char* Tag , int Count);

	//空
	bool CopyEmptyData(SquareData& Decision  , const char* ObjectName , SquareDirection Direction);

	//【タグが付いた複数の空】のコピー
	bool CopyEmptysData(SquareData& Decision , const char* Tag        , SquareDirection Direction , int Count);

//判定の更新
	void Update()
	{
		for (int Count = 0 ; Count < 2048; Count++)
		{
			BodyUpSetPosition(Count);
			BodyRightSetPosition(Count);
			BodyLeftSetPosition(Count);
			BodyDownSetPosition(Count);
		}
	}
	void SquareSetPosition(Vector2 Position , const char* ObjectName)
	{
		for (int Count = 0 ; Count < 2048; Count++)
		{
			if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
			{
				Position.x -= 960.0f;
				Position.y -= 540.0f;
				Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x = (Position.x - (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y = (Position.y + (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x = (Position.x + (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y = (Position.y - (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));
				return;
			}
		}
	}
	void CircleSetPosition(Vector2 Position , const char* ObjectName)
	{
		for (int Count = 0; Count < 2048; Count++)
		{
			if (strcmp(Circle[Count].ObjectName, ObjectName) == 0)
			{
				Position.x -= 960.0f;
				Position.y -= 540.0f;
				Circle[Count].Center.x = Position.x;
				Circle[Count].Center.y = Position.y;
				return;
			}
		}
	}

//判定の衝突
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
		Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertex.y  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y);
		Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y + (-EmptyWidth);
	}
	void BodyRightSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertex.x = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y + (EmptyWidth);
	}
	void BodyDownSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertex.y = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y);
	}
	void BodyLeftSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertex.x = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y + (EmptyWidth);
	}
private:
	SquareData Square[2048][5];
	CircleData Circle[2048];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;

	int a = 0;
};
