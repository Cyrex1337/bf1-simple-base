#pragma once

namespace fb
{
	class RenderView
	{
	public:
		D3DXMATRIX N0017A53B; //0x0000 
		D3DXMATRIX m_Transform; //0x0040 
		char _0x0080[ 544 ];
		D3DXMATRIX viewMatrix; //0x02A0 
		D3DXMATRIX viewMatrixTranspose; //0x02E0 
		D3DXMATRIX viewMatrixInverse; //0x0320 
		D3DXMATRIX projectionMatrix; //0x0360 
		D3DXMATRIX viewMatrixAtOrigin; //0x03A0 
		D3DXMATRIX projectionTranspose; //0x03E0 
		D3DXMATRIX projectionInverse; //0x0420 
		D3DXMATRIX viewProj; //0x0460 
		D3DXMATRIX viewProjTranspose; //0x04A0 
		D3DXMATRIX viewProjInverse; //0x04E0 
		char _0x0520[ 800 ];

	};//Size=0x0840
}