#include <io.h>
#include <d3d.h>
#include <fstream>
using std::ostream;



#ifdef PlaySound
#undef PlaySound
#endif

#ifdef Success
#undef Success
#endif


#if True
  #define __ZPROTO_B_VER3__
  #include "zPrototypes.h"
  #include "oPrototypes.h"
#endif

// startup
#ifdef __G2A
	#if True
	  #ifdef __ZPROTO_B_VER3__
		#define __ZINIT_B_VER3__
		#include "zMacro.h"
		#include "zInput_Const.h"
		#include "zTypes.h"
		#include "zSpyTypes.h"
		#include "zMemPool.h"
	  #endif
	#endif
#endif

// data, containers, cache, factory
#if True
  #ifdef __ZINIT_B_VER3__
    #define __ZCON_B_VER3__
    #include "zString.h"
    #include "zTypes3d.h"
    #include "zTools.h"
    #include "zAlgebra.h"
    #include "zContainer.h"
    #include "zList.h"
    #include "zSparseArray.h"
    #include "zObject.h"
    #include "zError.h"
  #endif
#endif

// input
#if True
  #ifdef __ZCON_B_VER3__
    #include "zInput_Win32.h"
  #endif
#endif

// z2D views, fonts, fx, etc
#if True
  #ifdef __ZCON_B_VER3__
    #define __Z2D_B_VER3__
    #include "zview.h"
    #include "zViewObject.h"
    #include "zViewDraw.h"
    #include "zViewFx.h"
    #include "zViewPrint_Font.h"
    #include "zViewPrint.h"
    #include "zViewDialog.h"
    #include "zViewDialogChoice.h"
    #include "zRndD3d.h"
    #include "zFonts.h"
    #include "zConsole.h"
  #endif
#endif

// o2D inventories, dialogs, documents, menu, etc
#if True
  #ifdef __Z2D_B_VER3__
    #define __O2D_B_VER3__
    #include "oViewDialogInventory.h"
    #include "oViewDialogItem.h"
    #include "oViewDialogItemContainer.h"
    #include "oViewDialogStealContainer.h"
    #include "oViewDialogTrade.h"
    #include "oViewStatusBar.h"
    #include "oDoc.h"
    #include "oDocumentManager.h"
    #include "oHelp.h"
    #include "oInfo.h"
    #include "oInformationManager.h"
    #include "oMenuSavegame.h"
    #include "oViewDocument.h"
    #include "oViewDocumentMap.h"
    #include "oViewProgressbar.h"
    #include "oMenu_Status.h"
    #include "oMenu_Help.h"
  #endif
#endif


// z3D mobs, npcs, zones, worlds, items, etc
#if True
  #ifdef __ZCON_B_VER3__
    #define __ZWLD_B_VER3__
    #include "zWorld.h"
    #include "oMusicZone.h"
    #include "oNpc.h"
    #include "oWorld.h"
    #include "oMobInter.h"
    #include "oSpawn.h"
    #include "oObjFactory.h"
  #endif
#endif

// sky
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZSKY_B_VER3__
    #include "zSky_Outdoor.h"
    #include "oBarrier.h"
  #endif
#endif


// visual, model, pfx, magic
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZVIS_B_VER3__
    #include "zLensflare.h"
    #include "zMorphMesh.h"
    #include "zPolyStrip.h"
    #include "zFlash.h"
    #include "zProgMesh.h"
    #include "zVertexTransform.h"
    #include "zPolyPool.h"
    #include "oVisFX.h"
    #include "oVisFx_MultiTarget.h"
    #include "oMagic.h"
    #include "oMagFrontier.h"
    #include "oParticleControl.h"
  #endif
#endif

// ai, physic, portals
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZAI_B_VER3__
    #include "zAIPlayer.h"
    #include "zPhysics.h"
    #include "zMoving.h"
    #include "oAIShoot.h"
    #include "oDialog.h"
    #include "oItemReact.h"
    #include "oFocus.h"
    #include "oNpcMessages.h"
    #include "oPortals.h"
    #include "oWaynet.h"
  #endif
#endif

// data system, vdfs
#if True
  #ifdef __ZCON_B_VER3__
    #define __ZFILE_B_VER3__
    #include "zDisk.h"
    #include "zArchiverGeneric.h"
    #include "zArchiver2.h"
    #include "zDisk_Vdfs.h"
    #include "zFile3d.h"
    #include "zFileCsv.h"
  #endif
#endif


// scripts, gameplay
#if True
  #ifdef __Z2D_B_VER3__
    #define __ZEXT_B_VER3__
    #include "zParser.h"
    #include "oSvm.h"
    #include "oText.h"
    #include "oMission.h"
    #include "oGuilds.h"
  #endif
#endif


// net
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZNET_B_VER3__
    #include "zQueue.h"
    #include "zNet.h"
    #include "zNetManager.h"
    #include "zNetEventMan.h"
    #include "zNetVobControl.h"
    #include "zNetVersion.h"
  #endif
#endif

// system, memory
#if True
  #ifdef __ZINIT_B_VER3__
    #define __ZHELP_B_VER3__
    #include "zMemory_Win32.h"
    #include "zMemory_Generic.h"
    #include "oSysInfo.h"
  #endif
#endif


// session
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZSES_B_VER3__
    #include "zAccount.h"
    #include "oGameManager.h"
    #include "oGame.h"
    #include "oGameInfo.h"
    #include "oPlayerInfo.h"
  #endif
#endif

// triggers, cutscenes
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZCS_B_VER3__
    #include "zCCsPool.h"
    #include "oCSPlayer.h"
    #include "oCSManager.h"
    #include "oCsProps.h"
    #include "oCsTrigger.h"
    #include "oTrigger.h"
  #endif
#endif

// render
#if True
  #ifdef __ZCON_B_VER3__
    #define __ZRND_B_VER3__
    #include "zRndD3d_Init.h"
    #include "zRenderLightContainer.h"
  #endif
#endif

// sound, music
#if True
  #ifdef __ZCON_B_VER3__
    #define __ZSND_B_VER3__
      #include "zMusicCtrl.h"
      #include "zSndMss.h"
  #endif
#endif

// video
#if True
  #ifdef __ZCON_B_VER3__
    #define __ZVID_B_VER3__
    #include "oBinkPlayer.h"
  #endif
#endif


// collisions
#if True
  #ifdef __ZWLD_B_VER3__
    #define __ZCOLL_B_VER3__
    #include "zConvexCollision.h"
    #include "zCollisionObjectMisc.h"
    #include "oCollisionObjectMiscChar.h"
  #endif
#endif

// other
#if False
  #include "zEigen.h"
  #include "zVobIdentifier.h"
  #include "zPrime.h"
#endif


#if 0
#include "zMacro.h"
#include "zInput_Const.h"
#include "zPrototypes.h"
#include "oPrototypes.h"
#include "zTypes.h"
#include "zSpyTypes.h"
#include "zMemPool.h"

#include "zContainer.h"
#include "zString.h"
#include "zList.h"
#include "zObject.h"
#include "zDisk.h"
#include "zParser.h"
#include "zAIPlayer.h"
#include "zLensflare.h"
#include "zMorphMesh.h"
#include "zPolyStrip.h"
#include "zSky_Outdoor.h"
#include "zVertexBuffer.h"
#include "zMusicCtrl.h"
#include "zAccount.h"
#include "zConsole.h"
#include "zEigen.h"
#include "zFlash.h"
#include "zInput_Win32.h"
#include "zMoving.h"
#include "zPhysics.h"
#include "zPrime.h"
#include "zProgMesh.h"
#include "zRenderLightContainer.h"
#include "zSndMss.h"
#include "zVertexTransform.h"
#include "zVobIdentifier.h"
#include "zWorldInfo.h"

#include "zview.h"
#include "zViewObject.h"
#include "zViewDraw.h"
#include "zViewFx.h"
#include "zViewPrint_Font.h"
#include "zViewPrint.h"
#include "zViewDialog.h"
#include "zViewDialogChoice.h"
#include "zRndD3d.h"
#include "zFonts.h"

#include "zRndD3d_Init.h"

#include "zSparseArray.h"
#include "zArchiverGeneric.h"
#include "zArchiver2.h"
#include "zDisk_Vdfs.h"
#include "zFile3d.h"
#include "zFileCsv.h"
#include "zPolyPool.h"

#include "zQueue.h"
#include "zNet.h"
#include "zNetManager.h"
#include "zNetEventMan.h"
#include "zNetVobControl.h"
#include "zNetVersion.h"

#include "zMemory_Win32.h"
#include "zMemory_Generic.h"
#include "zConvexCollision.h"


#include "oViewDialogInventory.h"
#include "oViewDialogItem.h"
#include "oViewDialogItemContainer.h"
#include "oViewDialogStealContainer.h"
#include "oViewDialogTrade.h"
#include "oViewStatusBar.h"
#include "oDoc.h"
#include "oDocumentManager.h"
#include "oHelp.h"
#include "oInfo.h"
#include "oInformationManager.h"
#include "oMenuSavegame.h"
#include "oViewDocument.h"
#include "oViewDocumentMap.h"
#include "oViewProgressbar.h"

#include "oVisFX.h"
#include "oVisFx_MultiTarget.h"

#include "oGame.h"
#include "oNPC.h"
#include "oMagic.h"
#include "oMission.h"
#include "oMobInter.h"
#include "oGameInfo.h"
#include "oGameManager.h"

#include "oAIShoot.h"
#include "oAIHuman.h"

#include "oAniCtrl.h"
#include "oFocus.h"
#include "oDialog.h"
#include "oGame.h"
#include "oGuilds.h"
#include "oNpcStates.h"
#include "oInventory.h"
#include "oNpcMessages.h"
#include "oSvm.h"
#include "oBinkPlayer.h"
#include "oCollisionObjectMiscChar.h"
#include "oItemReact.h"
#include "oParticleControl.h"
#include "oSysInfo.h"
#include "oText.h"

#include "zCCsPool.h"
#include "oCSPlayer.h"
#include "oCSManager.h"
#include "oCsProps.h"
#include "oCsTrigger.h"

#include "oMenu_Status.h"
#include "oMenu_Help.h"

#include "oPlayerInfo.h"
#include "oPortals.h"
#include "oSpawn.h"
#include "oMagFrontier.h"
#include "oTrigger.h"
#include "oObjFactory.h"
#include "oWorld.h"
#include "oBarrier.h"
#include "oWaynet.h"
#endif


#include "zGlobal.h"
