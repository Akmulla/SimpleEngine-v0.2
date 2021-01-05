#pragma once
#include <Windows.h>


class Window
{
public:
	Window(HINSTANCE);
	~Window();
	static Window* GetMainWindow();
};