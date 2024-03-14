#include "stdafx.h"
#include "Mouse.h"
#include "system/system.h"
#include "Storage2D/Header2D.h"
bool Mouse::Start()
{
	M_Client.x = GetSystemMetrics(SM_CXSCREEN);;
	M_Client.y = GetSystemMetrics(SM_CYSCREEN);

	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();
	P_Data2D->P_Collision2D->SquareDataSet(30, 30, M_Converted , "Mouse", "Non");
	return true;
}
void Mouse::Update()
{
    GetCursorPos(&M_CursorPosition);

    MouseSet();

	MouseMove();

	MouseFlagJudge();

	P_Data2D->P_Collision2D->SquareSetPosition(M_Converted , "Mouse");
}

void Mouse::MouseMove()
{
	M_Delta.x = M_Converted.x - M_PrevMouse.x;
	M_Delta.y = M_Converted.y - M_PrevMouse.y;

	M_DeltaTime = g_gameTime->GetFrameDeltaTime();
	M_DeltaSpeed.x = M_Delta.x / M_DeltaTime;
	M_DeltaSpeed.y = M_Delta.y / M_DeltaTime;
	
	M_PrevMouse.x = M_Converted.x;
	M_PrevMouse.y = M_Converted.y;
}
void Mouse::MouseSet()
{
	M_Converted.x = (M_CursorPosition.x * M_Window.x) / M_Client.x;
	M_Converted.y = M_Window.y - (M_CursorPosition.y * M_Window.y) / M_Client.y;
}

void Mouse::MouseFlagJudge()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		M_LeftClickFlag = true;
	}else{
		M_LeftClickFlag = false;
	}

	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		M_RightClickFlag = true;
	}else{
		M_RightClickFlag = false;
	}

	if (abs(M_DeltaSpeed.x) > FlickSpeedThreshold || abs(M_DeltaSpeed.y) > FlickSpeedThreshold)
	{
		M_FlickFlag = true;
	}else{
		M_FlickFlag = false;
	}

}
bool Mouse::GetMouseFlag(int Number)
{
	switch (Number)
	{
	case MOUSE_LEFTCLICK:
		return M_LeftClickFlag;
		break;
	case MOUSE_RIGHTCLICK:
		return M_RightClickFlag;
		break;
	case MOUSE_FLICK:
		return M_FlickFlag;
		break;
	}
}