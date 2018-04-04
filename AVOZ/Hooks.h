#pragma once

extern bool DoUnload;
extern bool bGlovesNeedUpdate;

#include "Utilities.h"

#ifdef NDEBUG
#define XorStringAlt( s ) ( XorCompileTime::XorStringAlt< sizeof( s ) - 1, __COUNTER__ >( s, std::make_index_sequence< sizeof( s ) - 1>() ).decrypt() )
#else
#define XorStringAlt( s ) ( s )
#endif

namespace Hooks
{
	void Initialise();
	void UndoHooks();

	extern Utilities::Memory::VMTManager VMTPanel; 
	extern Utilities::Memory::VMTManager VMTClient; 
	extern Utilities::Memory::VMTManager VMTClientMode;
	extern Utilities::Memory::VMTManager VMTModelRender;
	extern Utilities::Memory::VMTManager VMTPrediction; 
	extern Utilities::Memory::VMTManager VMTRenderView;
	extern Utilities::Memory::VMTManager VMTEventManager;
	extern Utilities::Memory::VMTManager VMTCreateMove;
};

namespace Resolver
{
	extern bool didhitHS;
}

extern bool flipAA;