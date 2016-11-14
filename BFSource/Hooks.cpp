#include "Hooks.hpp"
#include "Utils.hpp"

PresentFn oPresent;

// straight copypasted (@ReactiioN')
/*
using oBitBlt = int32_t( __stdcall* )( HDC, int32_t, int32_t, int32_t, int32_t, HDC, int32_t, int32_t, uint32_t );
oBitBlt g_BitBlt = nullptr;
bool g_CanRender = true;

int32_t __stdcall Hooks::hkBitBlt( HDC hdc_dest, int32_t x_dest, int32_t y_dest, int32_t width, int32_t height, HDC hdc_source, int32_t x_source, int32_t y_source, uint32_t raster_operation )
{
g_CanRender = false;
std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );

auto ret_value = g_BitBlt( hdc_dest, x_dest, y_dest, width, height, hdc_source, x_source, y_source, raster_operation );
std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
g_CanRender = true;

return ret_value;
}
*/

void ESP( )
{
	auto game_context = fb::ClientGameContext::Instance( );

	if ( !IsValidPtr( game_context ) )
		return;

	auto player_manager = game_context->GetPlayerManager( );

	if ( !IsValidPtr( player_manager ) )
		return;

	auto local_player = player_manager->GetLocalPlayer( );

	if ( !IsValidPtr( local_player ) )
		return;

	for ( unsigned int i = 0; i < player_manager->getPlayers( )->size( ); i++ )
	{
		auto cur_player = player_manager->getPlayers( )->at( i );

		if ( !IsValidPtr( cur_player ) )
			continue;

		auto is_friendly = local_player->m_TeamId == cur_player->m_TeamId;

		auto soldier = cur_player->GetSoldier( );

		if ( !IsValidPtr( soldier ) )
			continue;

		auto is_visible = !soldier->m_Occluded;

		auto position_foot = soldier->m_pClientSoldierPrediction->m_Position;
		DirectX::XMFLOAT3 position_head, position_foot_screen, position_head_screen;
		soldier->GetBonePos( BoneIds::BONE_Head, position_head );
		
		if (is_visible)		
			soldier->m_EngineChams = 240;//green
		else
			soldier->m_EngineChams = 242; //red
		
		soldier->m_RenderFlags &= 0xFFF7FFFF;

		/*
		if ( Utils::WorldToScreen( position_foot, position_foot_screen ) && Utils::WorldToScreen( position_head, position_head_screen ) )
		{
			auto h = position_foot_screen.y - position_head_screen.y;
			auto w = h / 3.f;

			if ( !is_visible )
				fb::DebugRenderer2::Instance( )->BorderBoxOutlined( position_foot_screen.x, position_head_screen.y, w, h, 1, is_friendly ? fb::Color32::Green( ) : fb::Color32::Red( ), fb::Color32::Black( ) );
			else
				fb::DebugRenderer2::Instance( )->BorderBoxOutlined( position_foot_screen.x, position_head_screen.y, w, h, 1, is_friendly ? fb::Color32::Green( ) : fb::Color32::Orange( ), fb::Color32::Black( ) );
		}
		*/
	}
}

HRESULT __stdcall Hooks::hkPresent( IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags )
{
	Utils::HandleDXScreenshot( );

	fb::DebugRenderer2::Instance( )->text_centered( fb::DXRenderer::Instance( )->m_pScreen->m_screenInfo.m_width / 2,
													20, fb::Color32::Orange( ), "Hallo" );

	ESP( );

	return oPresent( SwapChain, SyncInterval, Flags );
}
