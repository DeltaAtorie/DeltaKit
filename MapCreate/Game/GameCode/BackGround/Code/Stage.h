#pragma once
class Data2D;
enum class Wide
{
	SMALL  = 16,
	MEDIUM = 32,
	LARGE  = 64,
};
enum class Height
{
	SMALL  = 16,
	MEDIUM = 32,
	LARGE  = 64,
};
class Stage : public IGameObject
{
public:
	bool Start();
	void Setting(float Wide = 64.0f , float Height = 64.0f, float ScreenWide = 1920.0f, float ScreenHeight = 1080.0f);
private:
	SpriteRender MapCreate;
	Vector3 Pos;
	Data2D* P_Data2D = nullptr;
};

