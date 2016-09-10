//#pragma once
//
//#include <Windows.h>
//#include <unordered_map>
//
//#include "Defines.hpp"
//
//using HookFn = void( *)( PCONTEXT ctx );
//
//class VEH
//{
//public:
//	VEH( );
//
//public:
//	template <typename T>
//	static void Add( T address, HookFn proxy )
//	{
//		if ( !IsValidPtr( address ) )
//			return;
//
//		auto addr = reinterpret_cast< uintptr_t >( address );
//
//		m_HookedList[ addr ] = proxy;
//		DWORD old;
//		VirtualProtect( reinterpret_cast< void* >( address ), 1, PAGE_NOACCESS, &old );
//	}
//
//	template <typename T>
//	static void Remove( T address )
//	{
//		auto addr = reinterpret_cast< uintptr_t >( address );
//		m_HookedList[ addr ] = nullptr;
//		DWORD old;
//		VirtualProtect( reinterpret_cast< void* >( addr ), 1, PAGE_EXECUTE, &old );
//	}
//
//private:
//	static long __stdcall ExceptionHandler( PEXCEPTION_POINTERS ex );
//
//private:
//	static std::unordered_map<uintptr_t, HookFn> m_HookedList;
//};
