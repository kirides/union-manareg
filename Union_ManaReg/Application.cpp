#include "UnionAfx.h"


#ifdef __G2A
#define PLUGIN_NAMESPACE Gothic_II_Addon
#include "ManaReg.h"
#endif
#ifdef __G2
#define PLUGIN_NAMESPACE Gothic_II_Classic
#include "ManaReg.h"
#endif
#ifdef __G1A
#define PLUGIN_NAMESPACE Gothic_I_Classic
#include "ManaReg.h"
#endif
#ifdef __G1
#define PLUGIN_NAMESPACE Gothic_I_Addon
#include "ManaReg.h"
#endif

void Game_Entry() {
}

void Game_Init() {
}

void Game_Exit() {
}

void Game_Loop() {
	TEngineVersion engineVersion = Union.GetEngineVersion();
	switch (engineVersion)
	{
		case UnionCore::Engine_G1:
			Gothic_I_Classic::RegeneratePlayerMana_Loop();
			break;
		case UnionCore::Engine_G1A:
			Gothic_I_Addon::RegeneratePlayerMana_Loop();
			break;
		case UnionCore::Engine_G2:
			Gothic_II_Classic::RegeneratePlayerMana_Loop();
			break;
		case UnionCore::Engine_G2A:
			Gothic_II_Addon::RegeneratePlayerMana_Loop();
			break;
	}
}

void Game_SaveBegin() {
}

void Game_SaveEnd() {
}

void LoadBegin() {
}

void LoadEnd() {
}

void Game_LoadBegin_NewGame() {
	LoadBegin();
}

void Game_LoadEnd_NewGame() {
	LoadEnd();
}

void Game_LoadBegin_SaveGame() {
	LoadBegin();
}

void Game_LoadEnd_SaveGame() {
	LoadEnd();
}

void Game_LoadBegin_ChangeLevel() {
	LoadBegin();
}

void Game_LoadEnd_ChangeLevel() {
	LoadEnd();
}

void Game_LoadBegin_Trigger() {
}

void Game_LoadEnd_Trigger() {
}

void Game_Pause() {
}

void Game_Unpause() {
}

void Game_DefineExternals() {
}

CApplication* lpApplication = CApplication::CreateRefApplication (
	Game_Entry,
	Game_Init,
	Game_Exit,
	Game_Loop,
	Game_SaveBegin,
	Game_SaveEnd,
	Game_LoadBegin_NewGame,
	Game_LoadEnd_NewGame,
	Game_LoadBegin_SaveGame,
	Game_LoadEnd_SaveGame,
	Game_LoadBegin_ChangeLevel,
	Game_LoadEnd_ChangeLevel,
	Game_LoadBegin_Trigger,
	Game_LoadEnd_Trigger,
	Game_Pause,
	Game_Unpause,
	Game_DefineExternals
);