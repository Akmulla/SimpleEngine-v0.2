#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{
		case VK_UP:
			Input::SetVerticalAxis(1);
			break;
		case VK_DOWN:
			Input::SetVerticalAxis(-1);
			break;
		case VK_RIGHT:
			Input::SetHorizontalAxis(1);
			break;
		case VK_LEFT:
			Input::SetHorizontalAxis(-1);
			break;
		}
	}
	else
		if (uMsg == WM_KEYUP)
		{
			switch (wParam)
			{
			case VK_UP:
				Input::SetHorizontalAxis(0);
				break;
			case VK_DOWN:
				Input::SetHorizontalAxis(0);
				break;
			case VK_RIGHT:
				Input::SetHorizontalAxis(0);
				break;
			case VK_LEFT:
				Input::SetHorizontalAxis(0);
				break;
			}
		}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window* Window::mainWindow;

Window::Window(HINSTANCE hInstance)
{
	Window::mainWindow = this;

	const auto winClassName = "SimpleExampleWindowClass";
	WNDCLASSEX wc = { };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = winClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	hwnd = CreateWindowEx(
		0,
		winClassName,
		"MyWindow",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,
		200,
		1024,
		768,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	this->graphics = std::unique_ptr<Graphics>(new Graphics(hwnd));

	ShowWindow(hwnd, SW_SHOW);
}

Window::~Window()
{

}

void Window::DrawWindow()
{
	ColorRGBA c{ 1,0,0,1 };
	graphics->ClearBackground(c);

	graphics->EndFrame();
}

int Window::UpdateWindowsMessages()
{
	MSG msg;

	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return msg.wParam;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

Window* Window::GetMainWindow()
{
	return mainWindow;
}
