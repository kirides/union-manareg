// Supported with union (c) 2018 Union team

#ifndef __ZPARTICLE_H__VER2__
#define __ZPARTICLE_H__VER2__

namespace Gothic_II_Classic {
  const int zPARTICLE_MAX_GLOBAL = 4096;

  enum zTPFX_EmitterShape {
    zPFX_EMITTER_SHAPE_POINT,
    zPFX_EMITTER_SHAPE_LINE,
    zPFX_EMITTER_SHAPE_BOX,
    zPFX_EMITTER_SHAPE_CIRCLE,
    zPFX_EMITTER_SHAPE_SPHERE,
    zPFX_EMITTER_SHAPE_MESH
  };

  enum zTPFX_EmitterFOR {
    zPFX_FOR_WORLD,
    zPFX_FOR_OBJECT,
    zPFX_FOR_OBJECT_EACH_FRAME
  };

  enum zTPFX_EmitterDirMode {
    zPFX_EMITTER_DIRMODE_NONE,
    zPFX_EMITTER_DIRMODE_DIR,
    zPFX_EMITTER_DIRMODE_TARGET,
    zPFX_EMITTER_DIRMODE_MESH
  };

  enum zTPFX_EmitterVisOrient {
    zPFX_EMITTER_VISORIENT_NONE,
    zPFX_EMITTER_VISORIENT_VELO_ALIGNED,
    zPFX_EMITTER_VISORIENT_VOB_XZPLANE,
    zPFX_EMITTER_VISORIENT_VELO_ALIGNED3D
  };

  enum zTPFX_DistribType {
    zPFX_EMITTER_DISTRIBTYPE_RAND,
    zPFX_EMITTER_DISTRIBTYPE_UNIFORM,
    zPFX_EMITTER_DISTRIBTYPE_WALK
  };

  enum zTPFX_FlockMode {
    zPFX_FLOCK_NONE,
    zPFX_FLOCK_WIND,
    zPFX_FLOCK_WIND_PLANTS,
    zPFX_FLOCK_WIND_RAND
  };

  typedef struct zSParticle {
  public:
    zVEC3 position;
    zVEC3 positionWS;
    zVEC3 vel;
    float lifeSpan;
    float alpha;
    float alphaVel;
    zVEC2 size;
    zVEC2 sizeVel;
    zVEC3 color;
    zVEC3 colorVel;
    float flockFreeWillTime;
    zCPolyStrip* polyStrip;

    void zSParticle_OnInit() zCall( 0x005A7820 );
    zSParticle()             zInit( zSParticle_OnInit() );
  } zTParticle;

  class zCParticleEmitter {
  public:
    float ppsValue;
    zSTRING ppsScaleKeys_S;
    int ppsIsLooping;
    int ppsIsSmooth;
    float ppsFPS;
    zSTRING ppsCreateEm_S;
    float ppsCreateEmDelay;
    zSTRING shpType_S;
    zSTRING shpFOR_S;
    zSTRING shpOffsetVec_S;
    zSTRING shpDistribType_S;
    float shpDistribWalkSpeed;
    int shpIsVolume;
    zSTRING shpDim_S;
    zSTRING shpMesh_S;
    int shpMeshRender_B;
    zSTRING shpScaleKeys_S;
    int shpScaleIsLooping;
    int shpScaleIsSmooth;
    float shpScaleFPS;
    zSTRING dirMode_S;
    zSTRING dirFOR_S;
    zSTRING dirModeTargetFOR_S;
    zSTRING dirModeTargetPos_S;
    float dirAngleHead;
    float dirAngleHeadVar;
    float dirAngleElev;
    float dirAngleElevVar;
    float velAvg;
    float velVar;
    float lspPartAvg;
    float lspPartVar;
    zSTRING flyGravity_S;
    int flyCollDet_B;
    zSTRING visName_S;
    zSTRING visOrientation_S;
    int visTexIsQuadPoly;
    float visTexAniFPS;
    int visTexAniIsLooping;
    zSTRING visTexColorStart_S;
    zSTRING visTexColorEnd_S;
    zSTRING visSizeStart_S;
    float visSizeEndScale;
    zSTRING visAlphaFunc_S;
    float visAlphaStart;
    float visAlphaEnd;
    float trlFadeSpeed;
    zSTRING trlTexture_S;
    float trlWidth;
    float mrkFadeSpeed;
    zSTRING mrkTexture_S;
    float mrkSize;
    zSTRING m_flockMode_S;
    float m_fFlockWeight;
    int m_bSlowLocalFOR;
    zSTRING m_timeStartEnd_S;
    int m_bIsAmbientPFX;
    int endOfDScriptPart;
    zSTRING particleFXName;
    zCArray<float> ppsScaleKeys;
    zCParticleEmitter* ppsCreateEmitter;
    zTPFX_EmitterShape shpType;
    float shpCircleSphereRadius;
    zVEC3 shpLineBoxDim;
    zCMesh* shpMesh;
    zCPolygon* shpMeshLastPoly;
    zTPFX_EmitterFOR shpFOR;
    zTPFX_DistribType shpDistribType;
    zVEC3 shpOffsetVec;
    zCArray<float> shpScaleKeys;
    zTPFX_EmitterDirMode dirMode;
    zTPFX_EmitterFOR dirFOR;
    zTPFX_EmitterFOR dirModeTargetFOR;
    zVEC3 dirModeTargetPos;
    zTBBox3D dirAngleBox;
    zVEC3 dirAngleBoxDim;
    zVEC3 flyGravity;
    zCTexture* visTexture;
    zCMesh* visMesh;
    zTPFX_EmitterVisOrient visOrientation;
    zVEC2 visSizeStart;
    zVEC3 visTexColorRGBAStart;
    zVEC3 visTexColorRGBAEnd;
    zTRnd_AlphaBlendFunc visAlphaFunc;
    zCTexture* trlTexture;
    zCTexture* mrkTexture;
    int isOneShotFX;
    float dirAngleHeadVarRad;
    float dirAngleElevVarRad;
    zTPFX_FlockMode m_flockMode;
    float m_ooAlphaDist;
    float m_startTime;
    float m_endTime;

    void zCParticleEmitter_OnInit( zCParticleEmitter const& )  zCall( 0x005A8A70 );
    void zCParticleEmitter_OnInit()                            zCall( 0x005AD200 );
    zCParticleEmitter( zCParticleEmitter const& a0 )           zInit( zCParticleEmitter_OnInit( a0 ));
    zCParticleEmitter()                                        zInit( zCParticleEmitter_OnInit() );
    ~zCParticleEmitter()                                       zCall( 0x005AD520 );
    void UpdateVelocity()                                      zCall( 0x005AD860 );
    void AddCompoundReferences()                               zCall( 0x005AD870 );
    void ResetStrings()                                        zCall( 0x005AD8C0 );
    void Reset()                                               zCall( 0x005ADB60 );
    void UpdateInternals()                                     zCall( 0x005AE020 );
    void SetOutputDir( zVEC3 const& )                          zCall( 0x005AEE70 );
    void ConvertAnglesIntoBox()                                zCall( 0x005AF0B0 );
    zVEC3 GetPosition()                                        zCall( 0x005AF100 );
    zVEC3 __fastcall GetVelocity( zSParticle*, zCParticleFX* ) zCall( 0x005AF500 );
    zCParticleEmitter& operator =( zCParticleEmitter const& )  zCall( 0x007111E0 );
    static zVEC3 String2Vec3( zSTRING const& )                 zCall( 0x005ADB80 );
    static zVEC2 String2Vec2( zSTRING const& )                 zCall( 0x005ADE00 );
  };

  class zCParticleEmitterVars {
  public:
    float ppsScaleKeysActFrame;
    float ppsNumParticlesFraction;
    float ppsTotalLifeTime;
    int ppsDependentEmitterCreated;
    float shpScaleKeysActFrame;
    float uniformValue;
    float uniformDelta;

    zCParticleEmitterVars() {}
  };

  class zCParticleFX : public zCVisual {
  public:
    zCLASS_DECLARATION( zCParticleFX )

    class zCStaticPfxList {
    public:
      zCParticleFX* pfxListHead;
      zCParticleFX* pfxListTail;
      int numInList;

      zCStaticPfxList() {}
      void InsertPfxHead( zCParticleFX* ) zCall( 0x005A7C00 );
      void RemovePfx( zCParticleFX* )     zCall( 0x005A7C40 );
      void TouchPfx( zCParticleFX* )      zCall( 0x005A7CB0 );
      void ProcessList()                  zCall( 0x005A7D70 );
      int IsInList( zCParticleFX* )       zCall( 0x005A84B0 );
    };

    zTParticle* firstPart;
    zCParticleEmitterVars emitterVars;
    zCParticleEmitter* emitter;
    zTBBox3D bbox3DWorld;
    zCVob* connectedVob;
    int bboxUpdateCtr;
    group {
      unsigned char emitterIsOwned        : 1;
      unsigned char dontKillPFXWhenDone   : 1;
      unsigned char dead                  : 1;
      unsigned char isOneShotFX           : 1;
      unsigned char forceEveryFrameUpdate : 1;
      unsigned char renderUnderWaterOnly  : 1;
    };
    zCParticleFX* nextPfx;
    zCParticleFX* prevPfx;
    float privateTotalTime;
    float lastTimeRendered;
    float timeScale;
    float localFrameTimeF;
    zCQuadMark* quadMark;
    zTBBox3D quadMarkBBox3DWorld;
    float m_BboxYRangeInv;
    int m_bVisualNeverDies;

    void zCParticleFX_OnInit()                                        zCall( 0x005A78F0 );
    zCParticleFX()                                                    zInit( zCParticleFX_OnInit() );
    void InitEmitterVars()                                            zCall( 0x005A8550 );
    void FreeParticles()                                              zCall( 0x005A8570 );
    void RemoveEmitter()                                              zCall( 0x005A88E0 );
    int SetEmitter( zCParticleEmitter*, int )                         zCall( 0x005A8920 );
    int SetEmitter( zSTRING const&, int )                             zCall( 0x005A9460 );
    int SetAndStartEmitter( zSTRING const&, int )                     zCall( 0x005A9660 );
    int SetAndStartEmitter( zCParticleEmitter*, int )                 zCall( 0x005A9690 );
    void StopEmitterOutput()                                          zCall( 0x005A96C0 );
    void RestoreEmitterOutput()                                       zCall( 0x005A96D0 );
    int CalcIsDead()                                                  zCall( 0x005A99F0 );
    void UpdateParticleFX()                                           zCall( 0x005A9A80 );
    void CreateParticlesUpdateDependencies()                          zCall( 0x005A9B60 );
    void UpdateParticle( zSParticle* )                                zCall( 0x005A9E10 );
    float GetShapeScaleThisFrame()                                    zCall( 0x005AC2C0 );
    int GetNumParticlesThisFrame()                                    zCall( 0x005AC430 );
    void CheckDependentEmitter()                                      zCall( 0x005AC5D0 );
    void CreateParticles()                                            zCall( 0x005AC770 );
    static void operator delete( void* )                              zCall( 0x0048B940 );
    static zCObject* _CreateNewInstance()                             zCall( 0x005A6ED0 );
    static void ParseParticleFXScript()                               zCall( 0x005A7000 );
    static void InitParticleFX()                                      zCall( 0x005A74D0 );
    static void CleanupParticleFX()                                   zCall( 0x005A7830 );
    static zCParticleEmitter* SearchParticleEmitter( zSTRING const& ) zCall( 0x005A8720 );
    static zCParticleFX* Load( zSTRING const& )                       zCall( 0x005A9710 );
    static float PartRand()                                           zCall( 0x005A9A60 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x005A79F0 );
    virtual ~zCParticleFX()                                           zCall( 0x005A7A60 );
    virtual int Render( zTRenderContext& )                            zCall( 0x005AADB0 );
    virtual int IsBBox3DLocal()                                       zCall( 0x005A7A00 );
    virtual zTBBox3D GetBBox3D()                                      zCall( 0x005A98C0 );
    virtual zSTRING GetVisualName()                                   zCall( 0x005A8670 );
    virtual int GetVisualDied()                                       zCall( 0x005A7A10 );
    virtual void SetVisualUsedBy( zCVob* )                            zCall( 0x005A85C0 );
    virtual unsigned long GetRenderSortKey() const                    zCall( 0x005A7A20 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )          zCall( 0x005A7BF0 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )              zCall( 0x005A7BD0 );
    virtual zSTRING const* GetFileExtension( int )                    zCall( 0x005A84E0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const       zCall( 0x005A8540 );

    // static properties
    static zCParser*& s_pfxParser;
    static zCArraySort<zCParticleEmitter*>& s_emitterPresetList;
    static zCParticleEmitter& s_emitterDummyDefault;
    static int& s_bAmbientPFXEnabled;
    static int& s_globNumPart;
    static zTParticle*& s_globPartList;
    static zTParticle*& s_globFreePart;
    static zCMesh*& s_partMeshTri;
    static zCMesh*& s_partMeshQuad;
    static int& s_showDebugInfo;
    static zCStaticPfxList& s_pfxList;
  };

} // namespace Gothic_II_Classic

#endif // __ZPARTICLE_H__VER2__