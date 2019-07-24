#pragma once
#include "UnionAfx.h"
#ifdef __G2A
#define PLUGIN_NAMESPACE Gothic_II_Addon
#endif
/* TODO: FIX THIS FOR OTHER GOTHIC VERSIONS */
#ifdef __G2
#define PLUGIN_NAMESPACE Gothic_II
#endif
#ifdef __G1A
#define PLUGIN_NAMESPACE Gothic
#endif
#ifdef __G1
#define PLUGIN_NAMESPACE Gothic_Addon
#endif

namespace PLUGIN_NAMESPACE {

	// ---------------------------------
	// CLASS DEF: oCNpcEx
	// ---------------------------------
	class oCNpcEx : public oCNpc {
	public:
		zCLASS_UNION_DECLARATION(oCNpcEx);
		
		CTimer TimerAI;
		float RegenManaIntensity;

		oCNpcEx();
		
		void ProcessRegen();
		virtual void ProcessNpc();
	};

	// ---------------------------------
	// CLASS DEF: oCObjectFactoryEx
	// ---------------------------------
	class oCObjectFactoryEx : public oCObjectFactory {
		zCLASS_UNION_DECLARATION(oCObjectFactoryEx)
	public:
		virtual oCNpc* CreateNpc(int index);
	};
}