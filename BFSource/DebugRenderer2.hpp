#pragma once

namespace fb
{
	class DebugRenderer2
	{
	public:
		static DebugRenderer2* Instance( )
		{
			return reinterpret_cast< DebugRenderer2*( __stdcall* )( void ) >( 0x143eabd10 )( );
		}

	public:
		void border_box( const int32_t& x, const int32_t& y, const int32_t& w, const int32_t& h, const int32_t& thickness, const Color32& color )
		{
			rect( x, y, w, thickness, color );
			rect( x, y, thickness, h, color );
			rect( x + w, y, thickness, h, color );
			rect( x, y + h, w + thickness, thickness, color );
		}

		void BorderBoxOutlined( const int32_t& x, const int32_t& y, const int32_t& w, const int32_t& h, const int32_t& thickness, const Color32& color, const Color32& outlined )
		{
			border_box( x, y, w, h, thickness, color );
			border_box( x - 1, y - 1, w + thickness + 1, h + thickness + 1, 1, outlined );
			border_box( x + 1, y + 1, w + thickness - 2, h + thickness - 2, 1, outlined );
		}

		void line( const int32_t& x, const int32_t& y, const int32_t& xx, const int32_t& yy, const Color32& color )
		{
			auto start = eastl::Tuple2< float >( static_cast< float >( x ), static_cast< float >( y ) );
			auto stop = eastl::Tuple2< float >( static_cast< float >( xx ), static_cast< float >( yy ) );

			reinterpret_cast< void( __thiscall* )( DebugRenderer2*, eastl::Tuple2< float >*, eastl::Tuple2< float >*, Color32 ) >( 0x143eade60 )( this, &start, &stop, color );
		}

		void rect( const int32_t& x, const int32_t& y, const int32_t& w, const int32_t& h, const Color32& color )
		{
			auto mins = eastl::Tuple2< float >( static_cast< float >( x ), static_cast< float >( y ) );
			auto maxs = mins;
			maxs( 0 ) += w;
			maxs( 1 ) += h;
			reinterpret_cast< void( __thiscall* )( DebugRenderer2*, eastl::Tuple2< float >*, eastl::Tuple2< float >*, Color32 ) >( 0x143EAE080 )( this, &mins, &maxs, color );
		}

		void rect_outlined( const int32_t& x, const int32_t& y, const int32_t& w, const int32_t& h, const int32_t& thickness, const Color32& color, const Color32& outlined )
		{
			rect( x, y, w, h, color );
			border_box( x - thickness, y - thickness, w + thickness, h + thickness, thickness, outlined );
		}

		void text( const int32_t& x, const int32_t& y, const Color32& color, const char* text, ... )
		{
			va_list args;
			va_start( args, text );
			char buffer[ 0x400 ];
			vsprintf_s( buffer, 0x400, text, args );
			va_end( args );
			reinterpret_cast< void( __thiscall* )( DebugRenderer2*, int, int, char*, Color32, float ) >( 0x143EAE2E0 )( this, x, y, buffer, color, 1.f );
		}

		void text_centered( const int32_t& x, const int32_t& y, const Color32& color, const char* text, ... )
		{
			va_list args;
			va_start( args, text );
			char buffer[ 0x400 ];
			vsprintf_s( buffer, 0x400, text, args );
			va_end( args );
			reinterpret_cast< void( __thiscall* )( DebugRenderer2*, int, int, char*, Color32, float ) >( 0x143EAE2E0 )( this, x - static_cast< int >( strlen( buffer ) * 4.4 ), y, buffer, color, 1.f );
		}

		void corner_box( const int32_t x, const int32_t y, const int32_t w, const int32_t h, const bool outlined, const Color32& color, const Color32& outlined_color = 0xFF000000 )
		{
			auto corner = [&]( const int32_t _x, const int32_t _y, const int32_t width, const int32_t height, const bool right_side, const bool down, const Color32& _color, const bool _outlined = false, const Color32& _outlined_color = 0xFF000000 ) -> void {
				const auto corner_x = right_side ? _x - width : _x;
				const auto corner_y = down ? _y - height : _y;
				const auto corner_w = down && right_side ? width + 1 : width;

				rect( corner_x, _y, corner_w, 1, _color );
				rect( _x, corner_y, 1, height, _color );

				if ( _outlined )
				{
					rect( corner_x, down ? _y + 1 : _y - 1, !down && right_side ? corner_w + 1 : corner_w, 1, _outlined_color );
					rect( right_side ? _x + 1 : _x - 1, down ? corner_y : corner_y - 1, 1, down ? height + 2 : height + 1, _outlined_color );
				}
			};

			corner( x - w, y, w / 2, w / 2, false, false, color, outlined, outlined_color );
			corner( x - w, y + h, w / 2, w / 2, false, true, color, outlined, outlined_color );
			corner( x + w, y, w / 2, w / 2, true, false, color, outlined, outlined_color );
			corner( x + w, y + h, w / 2, w / 2, true, true, color, outlined, outlined_color );
		}
	};
}
