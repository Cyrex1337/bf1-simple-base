#pragma once

#include <cstdint>

namespace eastl
{
	template <typename T>
	class vector
	{
	public:
		unsigned int size( ) const
		{
			return ( reinterpret_cast< uintptr_t >( m_End ) - reinterpret_cast< uintptr_t >( m_FirstElement ) ) / sizeof( T );
		}

		T at( unsigned int index )
		{
			return *reinterpret_cast< T* >( reinterpret_cast< uintptr_t >( m_FirstElement ) + index * sizeof( T ) );
		}

		T operator[]( unsigned int index )
		{
			return at( index );
		}

	private:
		T* m_FirstElement = nullptr;
		T* m_End = nullptr;
		T* m_ArrayBound = nullptr;
		void* vftable = nullptr;
	};

	template< class T, int32_t T_Count, uint32_t T_PadSize>
	class fixed_vector
	{
	private:
		T* m_firstElement;
		T* m_lastElement;
		T* m_arrayBound;
		//PAD( T_PadSize );
		T m_data[ T_Count ];

	public:
		fixed_vector( void )
		{
			m_firstElement = reinterpret_cast< T* >( m_data );
			m_lastElement = reinterpret_cast< T* >( m_data );
			m_arrayBound = reinterpret_cast< T* >( &m_data[ T_Count ] );
		}

		void push_back( T *const value )
		{
			if ( m_lastElement > m_arrayBound )
			{
				return;
			}
			*m_lastElement = *value;
			m_lastElement = m_lastElement + 1;
		};

		void clear( void )
		{
			m_firstElement = m_data;
			m_lastElement = m_data;
		}

		uint32_t size( ) const
		{
			return m_lastElement - m_firstElement;
		}

		T at( size_t nIndex )
		{
			return m_firstElement[ nIndex ];
		}

		T operator []( size_t index )
		{
			return at( index );
		}
	};
}