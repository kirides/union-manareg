// Supported with union (c) 2018 Union team

#ifndef __ZTEXTURE_H__VER2__
#define __ZTEXTURE_H__VER2__

namespace Gothic_II_Classic {
  const int zTEX_PAL_SIZE_BYTES = 768;
  const int zTEX_LOAD_FLAG_TILE = 1;
  const int zTEX_MAX_ANIS       = 3;

  enum zTTexScaleSize {
    zTEX_SCALE_SIZE_XY_ONE_LOWER,
    zTEX_SCALE_SIZE_X_ONE_LOWER,
    zTEX_SCALE_SIZE_REFERENCE,
    zTEX_SCALE_SIZE_Y_ONE_HIGHER,
    zTEX_SCALE_SIZE_XY_ONE_HIGHER_EVERY_SECOND,
    zTEX_SCALE_SIZE_Y_XY_ONE_HIGHER_EVERY_SECOND,
    zTEX_SCALE_SIZE_XY_ONE_HIGHER,
    zTEX_SCALE_SIZE_XY_MAX,
    zTEX_SCALE_SIZE_COUNT
  };

  enum zTTexScaleBPP {
    zTEX_SCALE_BPP_S3TC,
    zTEX_SCALE_BPP_REFERENCE,
    zTEX_SCALE_BPP_ONE_HIGHER,
    zTEX_SCALE_BPP_MAX
  };

  enum zTTexLockMode {
    zTEX_LOCK_READ  = 1,
    zTEX_LOCK_WRITE = 2
  };

  struct zTTexPalette {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    zTTexPalette() {}
  };

  class zCTextureInfo {
  public:
    zTRnd_TextureFormat texFormat;
    int sizeX;
    int sizeY;
    int numMipMap;
    int refSizeX;
    int refSizeY;
    zCOLOR averageColor;

    zCTextureInfo() { ZeroMemory( this, sizeof( zCTextureInfo ) ); }
  };

  class zCTextureFileFormat : public zCObject {
  public:
    zCLASS_DECLARATION( zCTextureFileFormat )

    zCTextureFileFormat() {}
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005E9FC0 );
    virtual ~zCTextureFileFormat()                                zCall( 0x005EA000 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* ) zPureCall;
    virtual int LoadTexture( zFILE&, zCTextureExchange* )         zPureCall;
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* ) zPureCall;
    virtual int SaveTexture( zFILE&, zCTextureExchange* )         zPureCall;
    virtual zSTRING const& GetFileExtension() const               zPureCall;
    virtual int CanSave() const                                   zPureCall;
    virtual int CanLoad() const                                   zPureCall;
  };

  class zCTextureFileFormatTGA : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatTGA )

#pragma pack( push, 1 )
    struct zTTgaHeader {
    public:
      unsigned char IDLength;
      unsigned char CMapType;
      unsigned char ImgType;
      unsigned char CMapStartLo;
      unsigned char CMapStartHi;
      unsigned char CMapLengthLo;
      unsigned char CMapLengthHi;
      unsigned char CMapDepth;
      unsigned short XOffSet;
      unsigned short YOffSet;
      unsigned char WidthLo;
      unsigned char WidthHi;
      unsigned char HeightLo;
      unsigned char HeightHi;
      unsigned char PixelDepth;
      unsigned char ImageDescriptor;
    };
#pragma pack( pop )

    zTTgaHeader tgaHeader;
    zTRnd_TextureFormat texFormat;
    zCTextureInfo texInfo;
    unsigned char* palette;
    unsigned char* data;
    unsigned char* dataBase;
    int pitchXBytes;
    int tgaRLE;
    int tgaRLEflag;
    int tgaRLEcount;
    int tgaRLEsav[4];

    void zCTextureFileFormatTGA_OnInit()                          zCall( 0x005E9E70 );
    zCTextureFileFormatTGA()                                      zInit( zCTextureFileFormatTGA_OnInit() );
    int ReadTGAHeader( zFILE* )                                   zCall( 0x005EA060 );
    int ReadTGAColorMap( zFILE* )                                 zCall( 0x005EA740 );
    int ReadTGARLEPixel( zFILE*, unsigned char*, int )            zCall( 0x005EACC0 );
    int ReadTGASpan( zFILE*, unsigned char*, int, int )           zCall( 0x005EAF30 );
    int ReadTGAData( zFILE* )                                     zCall( 0x005EB040 );
    static zCObject* _CreateNewInstance()                         zCall( 0x005E99C0 );
    static void operator delete( void* )                          zCall( 0x005E9AD0 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005E9AF0 );
    virtual ~zCTextureFileFormatTGA()                             zCall( 0x005E9FA0 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005EB410 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )         zCall( 0x005EB2A0 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005E9B00 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )         zCall( 0x005E9B10 );
    virtual zSTRING const& GetFileExtension() const               zCall( 0x005EA010 );
    virtual int CanSave() const                                   zCall( 0x005E9B20 );
    virtual int CanLoad() const                                   zCall( 0x005E9B30 );
  };

  class zCTextureFileFormatInternal : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatInternal )

    zCTextureInfo texInfo;
    int numHigherThanRef;
    int maxPixelDim;
    int showSpyMessages;

    void zCTextureFileFormatInternal_OnInit()                     zCall( 0x005EB610 );
    zCTextureFileFormatInternal()                                 zInit( zCTextureFileFormatInternal_OnInit() );
    int ReadHeader( zFILE& )                                      zCall( 0x005EB7B0 );
    int ReadData( zFILE&, zCTextureExchange*, int )               zCall( 0x005EB810 );
    int WriteHeader( zFILE&, zCTextureExchange* )                 zCall( 0x005EBC40 );
    int WriteData( zFILE&, zCTextureExchange* )                   zCall( 0x005EBCB0 );
    static void operator delete( void* )                          zCall( 0x00436DF0 );
    static zCObject* _CreateNewInstance()                         zCall( 0x005E9D30 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005E9E40 );
    virtual ~zCTextureFileFormatInternal()                        zCall( 0x005EB750 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005EBB10 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )         zCall( 0x005EBA90 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005EBED0 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )         zCall( 0x005EBE10 );
    virtual zSTRING const& GetFileExtension() const               zCall( 0x005EB760 );
    virtual int CanSave() const                                   zCall( 0x005E9E50 );
    virtual int CanLoad() const                                   zCall( 0x005E9E60 );
  };

  class zCTextureExchange {
  public:

    zCTextureExchange() {}
    int GetMemSizeBytes()                                                    zCall( 0x005F14A0 );
    zVEC4 GetRGBAAtPtr( unsigned char*, zTTexPalette*, zTRnd_TextureFormat ) zCall( 0x005F1AB0 );
    static int CopyContents( zCTextureExchange*, zCTextureExchange* )        zCall( 0x005F1390 );
    virtual ~zCTextureExchange()                                             zCall( 0x005EC790 );
    virtual int Lock( int )                                                  zPureCall;
    virtual int Unlock()                                                     zPureCall;
    virtual int SetTextureInfo( zCTextureInfo const& )                       zPureCall;
    virtual void* GetPaletteBuffer()                                         zPureCall;
    virtual int GetTextureBuffer( int, void*&, int& )                        zPureCall;
    virtual zCTextureInfo GetTextureInfo()                                   zPureCall;
    virtual int CopyPaletteDataTo( void* )                                   zPureCall;
    virtual int CopyTextureDataTo( int, void*, int )                         zPureCall;
    virtual int HasAlpha()                                                   zPureCall;
    virtual zVEC4 GetRGBAAtTexel( float, float )                             zCall( 0x005F1550 );
  };

  class zCTextureConvert : public zCTextureExchange {
  public:

    zCTextureConvert() {}
    int LoadFromFileFormat( zSTRING const& )                  zCall( 0x005EE180 );
    int SaveToFileFormat( zSTRING const& )                    zCall( 0x005EE260 );
    int LoadFromFileFormat( zFILE&, zCTextureFileFormat* )    zCall( 0x005EE340 );
    int SaveToFileFormat( zFILE&, zCTextureFileFormat* )      zCall( 0x005EE370 );
    int SaveInternal( zFILE& )                                zCall( 0x005EE3A0 );
    int LoadInternal( zFILE& )                                zCall( 0x005EE430 );
    void ConvertToNewFormat( zTRnd_TextureFormat const& )     zCall( 0x005EE4C0 );
    void ConvertToNewSize( int, int )                         zCall( 0x005EE4F0 );
    void GenerateMipMaps()                                    zCall( 0x005EE5E0 );
    static int CalcNumMipMaps( unsigned long, unsigned long ) zCall( 0x005EE630 );
    static void CorrectAspectRatio( int&, int& )              zCall( 0x005EE660 );
    static void CorrectPow2( int&, int& )                     zCall( 0x005EE6E0 );
  };

  class zCTexture : public zCResource, public zCTextureExchange {
  public:
    zCLASS_DECLARATION( zCTexture )

    enum zTTexFileDesiredBPP {
      zTEX_FILE_DESIRED_BPP_S3TC,
      zTEX_FILE_DESIRED_BPP_8,
      zTEX_FILE_DESIRED_BPP_16,
      zTEX_FILE_DESIRED_BPP_32,
      zTEX_FILE_DESIRED_BPP_COUNT
    };

    zCTexture* nextAni[zTEX_MAX_ANIS];
    zCTexture* prevAni[zTEX_MAX_ANIS];
    int actAniFrame[zTEX_MAX_ANIS];
    int numAniFrames[zTEX_MAX_ANIS];
    group {
      unsigned char hasAlpha         : 1;
      unsigned char isAnimated       : 1;
      unsigned char changingRealtime : 1;
      unsigned char isTextureTile    : 1;
    };

    void zCTexture_OnInit()                                                                        zCall( 0x005EC5E0 );
    zCTexture()                                                                                    zInit( zCTexture_OnInit() );
    void InitValues()                                                                              zCall( 0x005EC6C0 );
    int IsLightmap() const                                                                         zCall( 0x005EC7C0 );
    zCTexture* GetAniTexture()                                                                     zCall( 0x005EC810 );
    void AddAniTex( int, zCTexture* )                                                              zCall( 0x005EC870 );
    void PrecacheTexAniFrames( float )                                                             zCall( 0x005EC8B0 );
    void ForceConvertAndReloadTexture()                                                            zCall( 0x005EF3C0 );
    int LoadAndConvertInternal( zFILE& )                                                           zCall( 0x005EF710 );
    int SaveAndConvertInternal( zFILE& )                                                           zCall( 0x005EFA90 );
    int CacheInNamed( zSTRING const* )                                                             zCall( 0x005EFC30 );
    int IsTextureTileBaseSlice() const                                                             zCall( 0x005F0640 );
    int CreateTextureTile( zCTextureExchange* )                                                    zCall( 0x005F0670 );
    void GetPixelSize( int&, int& )                                                                zCall( 0x005F0E20 );
    static zCTexture* SearchName( zSTRING& )                                                       zCall( 0x005EC7A0 );
    static zCTexture* Load( zSTRING&, int )                                                        zCall( 0x005EC8F0 );
    static zCTexture* LoadSingle( zSTRING&, int )                                                  zCall( 0x005ED5B0 );
    static int Exists( zSTRING& )                                                                  zCall( 0x005ED760 );
    static void AutoDetectRendererTexScale()                                                       zCall( 0x005ED930 );
    static void RefreshTexMaxSize( int )                                                           zCall( 0x005EE0F0 );
    static int ConvertTexture( zSTRING const& )                                                    zCall( 0x005EEC40 );
    static zTRnd_TextureFormat CalcNextBestTexFormat( zTRnd_TextureFormat )                        zCall( 0x005EF490 );
    static void CalcDesiredBPP( zSTRING const*, zTTexFileDesiredBPP&, zTRnd_TextureFormat&, int& ) zCall( 0x005EF590 );
    static void ScanConvertTextures( zSTRING )                                                     zCall( 0x005F1150 );
    static void operator delete( void* )                                                           zCall( 0x00766D50 );
    /* for zCResource num : 11*/
    virtual zCClassDef* _GetClassDef() const                                                       zCall( 0x005EC650 );
    virtual ~zCTexture()                                                                           zCall( 0x005EC6F0 );
    virtual int LoadResourceData()                                                                 zCall( 0x005EE720 );
    virtual int ReleaseResourceData()                                                              zCall( 0x005EE780 );
    virtual unsigned long GetResSizeBytes()                                                        zCall( 0x005EE7E0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& )                                  zCall( 0x005EE970 );
    virtual int GetChromaKeyingEnabled() const                                                     zCall( 0x005EC670 );
    virtual void SetChromaKeyingEnabled( int )                                                     zCall( 0x005EC680 );
    virtual void ReleaseData()                                                                     zPureCall;
    /* for zCTextureExchange num : 10*/
    virtual int Lock( int )                                                                        zPureCall;
    virtual int Unlock()                                                                           zPureCall;
    virtual int SetTextureInfo( zCTextureInfo const& )                                             zPureCall;
    virtual void* GetPaletteBuffer()                                                               zPureCall;
    virtual int GetTextureBuffer( int, void*&, int& )                                              zPureCall;
    virtual zCTextureInfo GetTextureInfo()                                                         zPureCall;
    virtual int CopyPaletteDataTo( void* )                                                         zPureCall;
    virtual int CopyTextureDataTo( int, void*, int )                                               zPureCall;
    virtual int HasAlpha()                                                                         zCall( 0x005EC660 );

    // static properties
    static zSTRING& zTEX_DEFAULT_TEXTURE_FILE;
    static zTTexScaleSize& s_texScaleSize;
    static zTTexScaleBPP& s_texScaleBPP;
    static unsigned long& s_texSupportedFormats;
    static char& s_useDefaultTex;
    static char& s_globalLoadTextures;
    static unsigned long& s_texMaxPixelSize;
    static zSTRING*& s_texDesiredBPPSuffix;
    static zTRnd_TextureFormat*& s_texDesiredBPPDefault;
    static float& s_texRefRAM;
    static zTTexFileDesiredBPP& s_texRefBPP;
  };

  class zCLightMap : public zCObject {
  public:
    zCLASS_DECLARATION( zCLightMap )

    zVEC3 lightmapOrigin;
    zVEC3 lightmapUVUp;
    zVEC3 lightmapUVRight;
    zCTexture* tex;

    void zCLightMap_OnInit()                                                   zCall( 0x005F20B0 );
    zCLightMap()                                                               zInit( zCLightMap_OnInit() );
    void SetTexture( zCTexture* )                                              zCall( 0x005F21E0 );
    void CalcLightmapOriginUpRight( zVEC3 const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005F2220 );
    static void operator delete( void* )                                       zCall( 0x0056C3F0 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x005F1FE0 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x005F20A0 );
    virtual ~zCLightMap()                                                      zCall( 0x005F2170 );
  };

  class zCTextureFileHandler : public zCScanDirFileHandler {
  public:

    zCTextureFileHandler() {}
    virtual ~zCTextureFileHandler()                                    zCall( 0x004248E0 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005F0E50 );
  };

} // namespace Gothic_II_Classic

#endif // __ZTEXTURE_H__VER2__