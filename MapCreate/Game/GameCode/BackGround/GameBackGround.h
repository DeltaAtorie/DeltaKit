#pragma once
#include "Code/Stage.h"

class Stage;

enum class BackGroundClass
{
	STAGE
};

class GameBackGround : public IGameObject
{
public:
	void BackGroundNewGO(BackGroundClass Class , int Order)
	{
		switch (Class)
		{
		case BackGroundClass::STAGE:
			P_Stage = NewGO<Stage>(Order , "stage");
			break;
		}
	}

	void BackGroundFindGO()
	{
		P_Stage = FindGO<Stage>("stage");
	}

	void BackGroundDeleteGO()
	{
		DeleteGO(P_Stage);
	}
	void BackGroundDeleteGO(BackGroundClass Class)
	{
		switch (Class)
		{
		case BackGroundClass::STAGE:
			DeleteGO(P_Stage);
			break;
		}
	}
public:
	Stage* P_Stage = nullptr;
};

