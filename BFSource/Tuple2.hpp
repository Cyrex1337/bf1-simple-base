#pragma once

namespace eastl
{
	template< typename T >
	class Tuple2
	{
	public:
		using Tuple = Tuple2< T >;

	public:
		Tuple2( void ) :
			m_Element1( static_cast< T >( 0 ) ),
			m_Element2( static_cast< T >( 0 ) )
		{ }

		Tuple2( T element1, T element2 ) :
			m_Element1( element1 ),
			m_Element2( element2 )
		{ }

		Tuple& operator = ( const Tuple& other )
		{
			for ( size_t i = 0; i < 2; ++i )
			{
				at( i ) = other( i );
			}
			return *this;
		}

		Tuple& operator = ( T value )
		{
			for ( size_t i = 0; i < 2; ++i )
			{
				at( i ) = value;
			}
			return *this;
		}

		T& operator () ( const size_t& nIndex )
		{
			return at( nIndex );
		}

		const T& operator () ( const size_t& nIndex ) const
		{
			return at( nIndex );
		}

		T& at( const size_t& nIndex )
		{
			return nIndex >= 1 ? m_Element2 : m_Element1;
		}

		const T& at( const size_t& nIndex ) const
		{
			return nIndex >= 1 ? m_Element2 : m_Element1;
		}

		T& first( void )
		{
			return at( 0 );
		}

		const T& first( void ) const
		{
			return at( 0 );
		}

		T& second( void )
		{
			return at( 1 );
		}
		const T& second( void ) const
		{
			return at( 1 );
		}

	private:
		T m_Element1;
		T m_Element2;
	};
}