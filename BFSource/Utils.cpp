#include "Utils.hpp"

// Spawn a CLI window and redirect I/O
void Utils::SpawnConsole( const char* title )
{
	AllocConsole( );
	FILE *conin, *conout;

	freopen_s( &conin, "conin$", "r", stdin );
	freopen_s( &conout, "conout$", "w", stderr );
	freopen_s( &conout, "conout$", "w", stdout );

	if ( title != nullptr )
		SetConsoleTitleA( title );
}

// Transforms a 3D world point in a 4D homogeneous screen point 
bool Utils::WorldToScreen( const DirectX::XMFLOAT3& world_point, DirectX::XMFLOAT3& out )
{
	auto view_x_projection = fb::GameRenderer::Instance( )->m_pRenderView->viewProj;

	auto mX = fb::DXRenderer::Instance( )->m_pScreen->m_screenInfo.m_width * 0.5f;
	auto mY = fb::DXRenderer::Instance( )->m_pScreen->m_screenInfo.m_height * 0.5f;

	auto w = view_x_projection( 0, 3 ) * world_point.x +
		view_x_projection( 1, 3 ) * world_point.y +
		view_x_projection( 2, 3 ) * world_point.z +
		view_x_projection( 3, 3 );

	if ( w < 0.001f )
	{
		out.z = w;
		return false;
	}

	auto x = view_x_projection( 0, 0 ) * world_point.x +
		view_x_projection( 1, 0 ) * world_point.y +
		view_x_projection( 2, 0 ) * world_point.z +
		view_x_projection( 3, 0 );

	auto y = view_x_projection( 0, 1 ) * world_point.x +
		view_x_projection( 1, 1 ) * world_point.y +
		view_x_projection( 2, 1 ) * world_point.z +
		view_x_projection( 3, 1 );

	out.x = mX * ( 1 + x / w );
	out.y = mY * ( 1 - y / w );
	out.z = w;

	return true;
}

// avoid calls to FF's DirectX screenshot function
void Utils::HandleDXScreenshot( )
{
	// might be outdated
	auto instance = *reinterpret_cast< uintptr_t* >( 0x143525658 );
	if ( !IsValidPtr( instance ) )
		return;

	auto retValue = *reinterpret_cast< uintptr_t* >( instance + 0x828 );
	if ( !IsValidPtr( retValue ) )
		return;

	*reinterpret_cast< byte* >( retValue + 0x73 ) = 0;
}
