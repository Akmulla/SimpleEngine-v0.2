#include "Graphics.h"

Graphics::Graphics(HWND hwnd)
{
	HRESULT hr = S_OK;

	DXGI_SWAP_CHAIN_DESC sd;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = hwnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	Microsoft::WRL::ComPtr<ID3D11Device> m_device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context;
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;

	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		swapChain.GetAddressOf(),
		m_device.GetAddressOf(),
		nullptr,
		m_context.GetAddressOf()
	);

	m_device.As(&m_pDevice);
	m_context.As(&m_pContext);
	swapChain.As(&m_pSwap);

	// Configure the back buffer and viewport.
	m_pSwap->GetBuffer(
		0,
		__uuidof(ID3D11Texture2D),
		(void**)&m_pBackBuffer);

	m_pBackBuffer->GetDesc(&m_bbDesc);

	ZeroMemory(&m_viewport, sizeof(D3D11_VIEWPORT));
	m_viewport.Height = (float)m_bbDesc.Height;
	m_viewport.Width = (float)m_bbDesc.Width;
	m_viewport.MinDepth = 0;
	m_viewport.MaxDepth = 1;


	m_pContext->RSSetViewports(
		1,
		&m_viewport
	);

	hr = m_pDevice->CreateRenderTargetView(
		m_pBackBuffer.Get(),
		nullptr,
		m_pTarget.GetAddressOf()
	);



	OutputDebugString("\nRender Target view initialized\n\n");
}

Graphics::~Graphics()
{

}

void Graphics::ClearBackground(const ColorRGBA colorRGBA)
{
	const float color[] = { colorRGBA.r,colorRGBA.g,colorRGBA.b,colorRGBA.a };
	m_pContext->ClearRenderTargetView(m_pTarget.Get(), color);
}

void Graphics::EndFrame()
{
	m_pSwap->Present(1u, 0u);
}

ID3D11Device* Graphics::GetDevice()
{
	return m_pDevice.Get();
}

ID3D11DeviceContext* Graphics::GetContext()
{
	return m_pContext.Get();
}

ID3D11RenderTargetView* Graphics::GetRenderTarget()
{
	return m_pTarget.Get();
}
