#include "stdafx.h"
#include "Collision2D.h"
//îªíËÇÃê∂ê¨
void Collision2D::SquareDataSet(float  Wide , float Height , Vector2 Position, const char* ObjectName , const char* Tag)
{
	for (int Count = 0 ; Count < 2048 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, "nullptr") == 0)
		{
			Position.x -= 960.0f;
			Position.y -= 540.0f;
			strcpy(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName , ObjectName);
			strcpy(Square[Count][static_cast<int>(SquareDirection::NON)].Tag        , Tag);
			Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x  = (Position.x - (Wide / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y  = (Position.y + (Height / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x = (Position.x + (Wide / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y = (Position.y - (Height / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].Wide               = (Wide);
			Square[Count][static_cast<int>(SquareDirection::NON)].Height             = (Height);
			BodyInSideDataSet(Count);
			return;
		}
	}
}
void Collision2D::CircleDataSet(float Radius , Vector2 Position , const char* ObjectName , const char* Tag)
{
	for (int Count = 0; Count < 2048; Count++)
	{
		if (strcmp(Circle[Count].ObjectName , "nullptr") == 0)
		{
			Position.x -= 960.0f;
			Position.y -= 540.0f;
			strcpy(Circle[Count].ObjectName , ObjectName);
			strcpy(Circle[Count].Tag        , Tag);
			Circle[Count].Center.x = Position.x;
			Circle[Count].Center.y = Position.y;
			Circle[Count].Radius   = Radius;
			return;
		}
	}
}

//îªíËÇÃï°êª
bool Collision2D::CopyBodyData(SquareData& Body , const char* ObjectName)
{
	for (int Count = 0 ; Count < 2048 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
		{
			strcpy(Body.ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
			strcpy(Body.Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
			Body.UpperLeftVertex.x  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x;
			Body.UpperLeftVertex.y  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y;
			Body.LowerRightVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x;
			Body.LowerRightVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y;
			return true;
		}
	}
	return false;
}
bool Collision2D::CopyBodyData(CircleData& Body , const char* ObjectName)
{
	for (int Count = 0; Count < 2048; Count++)
	{
		if (strcmp(Circle[Count].ObjectName , ObjectName) == 0)
		{
			strcpy(Body.ObjectName , Circle[Count].ObjectName);
			strcpy(Body.Tag        , Circle[Count].Tag);
			Body.Center.x  = Circle[Count].Center.x;
			Body.Center.y  = Circle[Count].Center.y;
			Body.Radius   = Circle[Count].Radius;
			return true;
		}
	}
	return false;
}

bool Collision2D::CopyBodysData(SquareData& Body , const char* Tag , int Count)
{
	if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].Tag, Tag) == 0)
	{
		strcpy(Body.ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
		strcpy(Body.Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
		Body.UpperLeftVertex.x  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.x;
		Body.UpperLeftVertex.y  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertex.y;
		Body.LowerRightVertex.x = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.x;
		Body.LowerRightVertex.y = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertex.y;
		return true;
	}
	return false;
}
bool Collision2D::CopyBodysData(CircleData& Body , const char* Tag , int Count)
{
	if (strcmp(Circle[Count].Tag , Tag) == 0)
	{
		strcpy(Body.ObjectName , Circle[Count].ObjectName);
		strcpy(Body.Tag        , Circle[Count].Tag);
		Body.Center.x = Circle[Count].Center.x;
		Body.Center.y = Circle[Count].Center.y;
		Body.Radius  = Circle[Count].Radius;
		return true;
	}
	return false;
}

bool Collision2D::CopyEmptyData(SquareData& Body , const char* ObjectName , SquareDirection Direction)
{
	for (int Count = 0 ; Count < 2048 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
		{
			Body.UpperLeftVertex.x  = Square[Count][static_cast<int>(Direction)].UpperLeftVertex.x;
			Body.UpperLeftVertex.y  = Square[Count][static_cast<int>(Direction)].UpperLeftVertex.y;
			Body.LowerRightVertex.x = Square[Count][static_cast<int>(Direction)].LowerRightVertex.x;
			Body.LowerRightVertex.y = Square[Count][static_cast<int>(Direction)].LowerRightVertex.y;
			return true;
		}
	}
	return false;
}
bool Collision2D::CopyEmptysData(SquareData& Body , const char* Tag , SquareDirection Direction , int Count)
{
	if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].Tag, Tag) == 0)
	{
		strcpy(Body.ObjectName , Square[Count][static_cast<int>(Direction)].ObjectName);
		strcpy(Body.Tag        , Square[Count][static_cast<int>(Direction)].Tag);
		Body.UpperLeftVertex.x  = Square[Count][static_cast<int>(Direction)].UpperLeftVertex.x;
		Body.UpperLeftVertex.y  = Square[Count][static_cast<int>(Direction)].UpperLeftVertex.y;
		Body.LowerRightVertex.x = Square[Count][static_cast<int>(Direction)].LowerRightVertex.x;
		Body.LowerRightVertex.y = Square[Count][static_cast<int>(Direction)].LowerRightVertex.y;
		return true;
	}
	return false;
}

//è’ìÀîªíË
bool Collision2D::SquareAndSquare(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2 , CrashType Type)
{
	SquareData Body1;
	SquareData Body2;

	if (Type != CrashType::EtoE)
	{return false;}

	CopyEmptyData(Body1, ObjectName1, Direction1);
	CopyEmptyData(Body2, ObjectName2, Direction2);

	for (int X = Body1.UpperLeftVertex.x; X <= Body1.LowerRightVertex.x; X++)
	{
		for (int Y = Body1.LowerRightVertex.y; Y <= Body1.UpperLeftVertex.y; Y++)
		{
			if ((X >= Body2.UpperLeftVertex.x && X <= Body2.LowerRightVertex.x) && (Y <= Body2.UpperLeftVertex.y && Y >= Body2.LowerRightVertex.y))
			{
				return true;
			}
		}
	}
	return false;
}
bool Collision2D::SquareAndSquare(const char* ObjectName1, const char* ObjectName2, CrashType Type)
{
	SquareData Body1;
	SquareData Body2;

	if (Type != CrashType::BtoB)
	{return false;}

	CopyBodyData(Body1 , ObjectName1);
	CopyBodyData(Body2 , ObjectName2);

	for (int X = Body1.UpperLeftVertex.x; X <= Body1.LowerRightVertex.x; X++)
	{
		for (int Y = Body1.LowerRightVertex.y; Y <= Body1.UpperLeftVertex.y; Y++)
		{
			if ((X >= Body2.UpperLeftVertex.x && X <= Body2.LowerRightVertex.x) && (Y <= Body2.UpperLeftVertex.y && Y >= Body2.LowerRightVertex.y))
			{
				return true;
			}
		}
	}
	return false;
}
bool Collision2D::SquareAndSquare(const char* ObjectName1, const char* ObjectName2, SquareDirection Direction2, CrashType Type)
{
	SquareData Body1;
	SquareData Body2;

	if (Type != CrashType::BtoE)
	{return false;}

	CopyBodyData(Body1  , ObjectName1);
	CopyEmptyData(Body2 , ObjectName2 , Direction2);

	for (int X = Body1.UpperLeftVertex.x; X <= Body1.LowerRightVertex.x; X++)
	{
		for (int Y = Body1.LowerRightVertex.y; Y <= Body1.UpperLeftVertex.y; Y++)
		{
			if ((X >= Body2.UpperLeftVertex.x && X <= Body2.LowerRightVertex.x) && (Y <= Body2.UpperLeftVertex.y && Y >= Body2.LowerRightVertex.y))
			{
				return true;
			}
		}
	}
	return false;
}

bool Collision2D::CircleAndCircle(const char* ObjectName1 , const char* ObjectName2 , CrashType Type)
{
	CircleData Body1;
	CircleData Body2;

	float Pi = 3.14159265358979323846f;

	if (Type != CrashType::BtoB)
	{return false;}

	CopyBodyData(Body1 , ObjectName1);
	CopyBodyData(Body2 , ObjectName2);

	for (Body1.Angle = 0.0f; Body1.Angle < 360.0f; Body1.Angle += 1.0f)
	{
		Body1.Radian = Body1.Angle * Pi / 180.0f;

		Body1.Circle.x = cos(Body1.Radian) * Body1.Radius;
		Body1.Circle.y = sin(Body1.Radian) * Body1.Radius;

		Body1.Circle.x += Body1.Center.x;
		Body1.Circle.y += Body1.Center.y;

		for (Body2.Angle = 0.0f; Body2.Angle < 360.0f; Body2.Angle += 1.0f)
		{
			Body2.Radian = Body2.Angle * Pi / 180.0f;

			Body2.Circle.x = cos(Body2.Radian) * Body2.Radius;
			Body2.Circle.y = sin(Body2.Radian) * Body2.Radius;

			Body2.Circle.x += Body2.Center.x;
			Body2.Circle.y += Body2.Center.y;

			//âEè„
			if (Body1.Circle.x >= Body2.Center.x && Body1.Circle.y >= Body2.Center.y)
			{
				if (Body1.Circle.x <= Body2.Circle.x && Body1.Circle.y <= Body2.Circle.y)
				{
					return true;
				}
			}

			//âEâ∫
			if (Body1.Circle.x >= Body2.Center.x && Body1.Circle.y <= Body2.Center.y)
			{
				if (Body1.Circle.x <= Body2.Circle.x && Body1.Circle.y >= Body2.Circle.y)
				{
					return true;
				}
			}

			//ç∂è„
			if (Body1.Circle.x <= Body2.Center.x && Body1.Circle.y >= Body2.Center.y)
			{
				if (Body1.Circle.x >= Body2.Circle.x && Body1.Circle.y <= Body2.Circle.y)
				{
					return true;
				}
			}

			//ç∂â∫
			if (Body1.Circle.x <= Body2.Center.x && Body1.Circle.y <= Body2.Center.y)
			{
				if (Body1.Circle.x >= Body2.Circle.x && Body1.Circle.y >= Body2.Circle.y)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool Collision2D::SquareAndCircle(CrashType Type)
{
	return false;
}