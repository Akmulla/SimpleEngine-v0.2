#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <sstream>
#include <string>
#include <memory>
#include "Graphics.h"
#include "Input.h"
#include "Scene.h"
#include "GameObject.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

class Window
{
public:
	Window(HINSTANCE);
	~Window();
	void DrawWindow(Scene&);
	int UpdateWindowsMessages();
	Graphics* GetGraphics();
	static Window* GetMainWindow();
private:
	static Window* mainWindow;
	HWND hwnd;
	std::unique_ptr<Graphics> graphics;
};