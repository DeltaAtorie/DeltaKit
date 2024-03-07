#pragma once
#include "Code/Ui.h"

class Ui;

enum class SpriteClass
{
	UI
};

class GameSprite : public IGameObject
{
public:
	void SpriteNewGO(SpriteClass Class , int Order)
	{
		switch (Class)
		{
		case SpriteClass::UI:
			P_Ui = NewGO<Ui>(Order, "ui");
			break;
		}
	
	}

	void SpriteFindGO()
	{
		P_Ui = FindGO<Ui>("ui");
	}

	void SpriteDeleteGO()
	{
		DeleteGO(P_Ui);
	}
	void SpriteDeleteGO(SpriteClass Class)
	{
		switch (Class)
		{
		case SpriteClass::UI:
			DeleteGO(P_Ui);
			break;
		}
	}
public:
	Ui* P_Ui = nullptr;
};