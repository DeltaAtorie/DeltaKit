#include "stdafx.h"
#include "Stage.h"
#include "Storage2D/Header2D.h"
bool Stage::Start()
{
	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();
	return true;
}

void Stage::Setting(float Wide , float Height , float ScreenWide , float ScreenHeight)
{
	/*
	1920
	64pi : 30
	32pi : 60
	16pi : 120
	*/

	/*
	1080
	64pi : 1024
	32pi : 1056
	16pi : 1072
	*/

	const char* Name = "Non";
	const char* Tag  = "Non";
	//P_Data2D->P_Collision2D->SquareDataSet(Wide , Height , 0.0f, 0.0f, Name, Tag);
}