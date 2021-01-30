#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include "Colors.h"
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib,"D3DCompiler.lib")

class Graphics
{
public:
	Graphics(HWND hwnd);
	~Graphics();
	void ClearBackground(const ColorRGBA);
	void EndFrame();
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
private:
	Microsoft::WRL::ComPtr <ID3D11Texture2D> m_pBackBuffer;
	Microsoft::WRL::ComPtr<ID3D11Device> m_pDevice;
	Microsoft::WRL::ComPtr<IDXGISwapChain> m_pSwap;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pTarget;

	D3D11_VIEWPORT          m_viewport;
	D3D11_TEXTURE2D_DESC    m_bbDesc;
};