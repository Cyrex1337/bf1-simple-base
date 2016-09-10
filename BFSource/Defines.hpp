#pragma once

#ifdef _AMD64_
constexpr void* ptr_max_value = 0x000F000000000000;
#else
constexpr void* ptr_max_value = reinterpret_cast< void* >( 0xFFF00000 );
#endif

template <typename T>
bool IsValidPtr( T p )
{
	return reinterpret_cast< void* >( p ) >= reinterpret_cast< void* >( 0x10000 ) && reinterpret_cast< void* >( p ) < ptr_max_value;
}