//#pragma once
#ifdef PLUGIN_NAMESPACE
#include "UnionAfx.h"
//#include <math.h>

namespace PLUGIN_NAMESPACE {
	extern void RegeneratePlayerMana_Loop();

	void RegeneratePlayerMana_Loop() {
		static CTimer TimerAI;
		static const uint RegenManaID = 1;

		auto p = player;
		if (p) {
			TimerAI.Suspend(RegenManaID, ogame->singleStep);
			if (p->attribute[NPC_ATR_MANA] < p->attribute[NPC_ATR_MANAMAX]) {
				int menge; menge = (p->attribute[NPC_ATR_MANAMAX] + (50 / 2)) / 50;
				int ManaIntensity = (2000.0f / max(menge, 1));
				if (TimerAI(RegenManaID, ManaIntensity)) {
					p->attribute[NPC_ATR_MANA]++;
				}
			}
			TimerAI.Attach();
		}
	}
}
#endif