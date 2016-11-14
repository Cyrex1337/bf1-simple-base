#pragma once

namespace fb
{
	class RenderView
	{
	public:
		DirectX::XMFLOAT4X4 N0017A53B; //0x0000 
		DirectX::XMFLOAT4X4 m_Transform; //0x0040 
		char _0x0080[ 544 ];
		DirectX::XMFLOAT4X4 viewMatrix; //0x02A0 
		DirectX::XMFLOAT4X4 viewMatrixTranspose; //0x02E0 
		DirectX::XMFLOAT4X4 viewMatrixInverse; //0x0320 
		DirectX::XMFLOAT4X4 projectionMatrix; //0x0360 
		DirectX::XMFLOAT4X4 viewMatrixAtOrigin; //0x03A0 
		DirectX::XMFLOAT4X4 projectionTranspose; //0x03E0 
		DirectX::XMFLOAT4X4 projectionInverse; //0x0420 
		DirectX::XMFLOAT4X4 viewProj; //0x0460 
		DirectX::XMFLOAT4X4 viewProjTranspose; //0x04A0 
		DirectX::XMFLOAT4X4 viewProjInverse; //0x04E0 
		char _0x0520[ 800 ];

	};//Size=0x0840
}