#pragma once

#include <cstdint>
#include "Defines.hpp"

namespace eastl
{
	template <typename T>
	class weakptr
	{
	public:
		T* get_data( )
		{
			if ( !IsValidPtr( m_ptr ) )
				return nullptr;

			return reinterpret_cast< T* >( reinterpret_cast< uintptr_t >( *m_ptr ) - sizeof( uintptr_t ) );
		}

	private:
		T** m_ptr;
	};
}