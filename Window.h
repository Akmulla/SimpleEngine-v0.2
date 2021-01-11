#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <sstream>
#include <string>
#include <memory>
#include "Graphics.h"

class Window
{
public:
	Window(HINSTANCE);
	~Window();
	static Window* GetMainWindow();
private:
	static Window* mainWindow;
	HWND hwnd;
	std::unique_ptr<Graphics> graphics;
};