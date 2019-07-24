#include "ManaReg.h"

namespace PLUGIN_NAMESPACE {
	zCLASS_UNION_DEFINITION(oCNpcEx, oCNpc, 0, 0);
	zCLASS_UNION_DEFINITION(oCObjectFactoryEx, oCObjectFactory, 0, 0);


	oCNpcEx::oCNpcEx() : oCNpc() {
		RegenManaIntensity = 1.0f;
	}

	void oCNpcEx::ProcessRegen() {
		static const uint RegenManaID = 1;
		static const uint UnlockID    = 999;

		TimerAI.Suspend(RegenManaID, ogame->singleStep);
		if (attribute[NPC_ATR_MANA] < attribute[NPC_ATR_MANAMAX]) {
			ogame->game_text->PrintMessage("DERP", "HERP", 10, zCOLOR(255, 255, 0, 0));
			int ManaIntensity = (1000.0f / RegenManaIntensity);
			if (TimerAI(RegenManaID, ManaIntensity)) {
				attribute[NPC_ATR_MANA]++;
			}
		}
	}
	void oCNpcEx::ProcessNpc() {
		TimerAI.Attach();
		if (this == player) {
			ProcessRegen();
		}
		oCNpc::ProcessNpc();
	}

	oCNpc* oCObjectFactoryEx::CreateNpc(int index) {
		oCNpc* npc = new oCNpcEx();

		if (index != zPAR_INDEX_UNDEF)
			npc->InitByScript(index, 0);

		return npc;
	}
}