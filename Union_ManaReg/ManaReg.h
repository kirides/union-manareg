#ifdef PLUGIN_NAMESPACE
#include "UnionAfx.h"
#include <Windows.h>

namespace PLUGIN_NAMESPACE {
	extern void RegeneratePlayerMana_Loop();
	extern void RegeneratePlayerMana_LoadSettings();

	static int g_regRate = 2;
	static float g_regTickRate = 2000.0f;

	void RegeneratePlayerMana_Loop() {
		static CTimer TimerAI;
		static const uint RegenManaID = 1;

		auto p = player;
		if (p) {
			TimerAI.Suspend(RegenManaID, ogame->singleStep);
			if (p->attribute[NPC_ATR_MANA] < p->attribute[NPC_ATR_MANAMAX]) {
				int menge; menge = (p->attribute[NPC_ATR_MANAMAX] * g_regRate) / 100;

				int ManaIntensity = (g_regTickRate / max(menge, 1));
				if (TimerAI(RegenManaID, ManaIntensity)) {
					p->attribute[NPC_ATR_MANA]++;
				}
			}
			TimerAI.Attach();
		}
	}

	void RegeneratePlayerMana_LoadSettings() {
		TCHAR NPath[MAX_PATH];
		// Returns Gothic directory.
		int len = GetCurrentDirectory(MAX_PATH, NPath);
		// Get path to Gothic.Ini
		auto ini = std::string(NPath, len).append("\\system\\Gothic.ini");

		g_regRate = GetPrivateProfileInt("UNION_MANAREG", "iVALUE", 2, ini.c_str());
		g_regTickRate = GetPrivateProfileInt("UNION_MANAREG", "iTICKRATE", 2000, ini.c_str());
	}
}
#endif