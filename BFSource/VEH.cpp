//#include "VEH.hpp"
//
//VEH::VEH( )
//{
//	AddVectoredExceptionHandler( 1, &ExceptionHandler );
//}
//
//uintptr_t lastUnhooked;
//long VEH::ExceptionHandler(PEXCEPTION_POINTERS ex)
//{
//	DWORD old;
//
//	if ( ex->ExceptionRecord->ExceptionCode != STATUS_ACCESS_VIOLATION && ex->ExceptionRecord->ExceptionCode != STATUS_SINGLE_STEP )
//		return EXCEPTION_CONTINUE_SEARCH;
//
//	if ( ex->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP )
//	{
//		VirtualProtect( reinterpret_cast< void* >( lastUnhooked ), 1, PAGE_NOACCESS, &old );
//		return EXCEPTION_CONTINUE_EXECUTION;
//	}
//
//	auto it = m_HookedList.find( ex->ContextRecord->Eip );
//	if ( it != m_HookedList.end( ) )
//		it->second( ex->ContextRecord );
//
//	lastUnhooked = ex->ContextRecord->Eip;
//	VirtualProtect( reinterpret_cast< void* >( ex->ContextRecord->Eip ), 1, PAGE_EXECUTE, &old );
//	ex->ContextRecord->EFlags |= 0x100;
//	return EXCEPTION_CONTINUE_EXECUTION;
//}
