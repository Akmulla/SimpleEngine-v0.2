#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include "GameObject.h"
#include <wrl.h>
#include "Colors.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib,"D3DCompiler.lib")

class Graphics
{
public:
	Graphics(HWND hwnd);
	~Graphics();
	void ClearBackground(const ColorRGBA);
	void EndFrame();
private:
	Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwap;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pTarget;
};