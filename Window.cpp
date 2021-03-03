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
				Input::SetVerticalAxis(0);
				break;
			case VK_DOWN:
				Input::SetVerticalAxis(0);
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
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(graphics->GetDevice(), graphics->GetContext());

	
}

Window::~Window()
{

}

void Window::DrawWindow(Scene& scene)
{
	ColorRGBA c{ 255,255,255,0 };
	graphics->ClearBackground(c);

	for (auto it = scene.gameObjects.begin(); it != scene.gameObjects.end(); ++it)
	{
		(*it)->Draw();
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Hello, world!");
	ImGui::Text("This is some useful text.");
	ImGui::End();
	ImGui::Render();

	//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	//const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
	//static ID3D11RenderTargetView* g_mainRenderTargetView = graphics->GetRenderTarget();
	//graphics->GetContext()->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
	//graphics->GetContext()->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

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

Graphics* Window::GetGraphics()
{
	return graphics.get();
}

Window* Window::GetMainWindow()
{
	return mainWindow;
}
