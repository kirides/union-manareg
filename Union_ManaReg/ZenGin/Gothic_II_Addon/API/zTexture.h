// Supported with union (c) 2018 Union team

#ifndef __ZTEXTURE_H__VER3__
#define __ZTEXTURE_H__VER3__

#include "zResource.h"
#include "zRenderer.h"
#include "zScanDir.h"

namespace Gothic_II_Addon {
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
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005F0D70 );
    virtual ~zCTextureFileFormat()                                zCall( 0x005F0DB0 );
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

    void zCTextureFileFormatTGA_OnInit()                          zCall( 0x005F0C20 );
    zCTextureFileFormatTGA()                                      zInit( zCTextureFileFormatTGA_OnInit() );
    int ReadTGAHeader( zFILE* )                                   zCall( 0x005F0E10 );
    int ReadTGAColorMap( zFILE* )                                 zCall( 0x005F14F0 );
    int ReadTGARLEPixel( zFILE*, unsigned char*, int )            zCall( 0x005F1A70 );
    int ReadTGASpan( zFILE*, unsigned char*, int, int )           zCall( 0x005F1CE0 );
    int ReadTGAData( zFILE* )                                     zCall( 0x005F1DF0 );
    static zCObject* _CreateNewInstance()                         zCall( 0x005F0770 );
    static void operator delete( void* )                          zCall( 0x005F0880 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005F08A0 );
    virtual ~zCTextureFileFormatTGA()                             zCall( 0x005F0D50 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005F21C0 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )         zCall( 0x005F2050 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005F08B0 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )         zCall( 0x005F08C0 );
    virtual zSTRING const& GetFileExtension() const               zCall( 0x005F0DC0 );
    virtual int CanSave() const                                   zCall( 0x005F08D0 );
    virtual int CanLoad() const                                   zCall( 0x005F08E0 );
  };

  class zCTextureFileFormatInternal : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatInternal )

    zCTextureInfo texInfo;
    int numHigherThanRef;
    int maxPixelDim;
    int showSpyMessages;

    void zCTextureFileFormatInternal_OnInit()                     zCall( 0x005F23C0 );
    zCTextureFileFormatInternal()                                 zInit( zCTextureFileFormatInternal_OnInit() );
    int ReadHeader( zFILE& )                                      zCall( 0x005F2560 );
    int ReadData( zFILE&, zCTextureExchange*, int )               zCall( 0x005F25C0 );
    int WriteHeader( zFILE&, zCTextureExchange* )                 zCall( 0x005F29F0 );
    int WriteData( zFILE&, zCTextureExchange* )                   zCall( 0x005F2A60 );
    static void operator delete( void* )                          zCall( 0x004372F0 );
    static zCObject* _CreateNewInstance()                         zCall( 0x005F0AE0 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005F0BF0 );
    virtual ~zCTextureFileFormatInternal()                        zCall( 0x005F2500 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005F28C0 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )         zCall( 0x005F2840 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* ) zCall( 0x005F2C80 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )         zCall( 0x005F2BC0 );
    virtual zSTRING const& GetFileExtension() const               zCall( 0x005F2510 );
    virtual int CanSave() const                                   zCall( 0x005F0C00 );
    virtual int CanLoad() const                                   zCall( 0x005F0C10 );
  };

  class zCTextureExchange {
  public:

    zCTextureExchange() {}
    int GetMemSizeBytes()                                                    zCall( 0x005F8290 );
    zVEC4 GetRGBAAtPtr( unsigned char*, zTTexPalette*, zTRnd_TextureFormat ) zCall( 0x005F88A0 );
    static int CopyContents( zCTextureExchange*, zCTextureExchange* )        zCall( 0x005F8180 );
    virtual ~zCTextureExchange()                                             zCall( 0x005F3540 );
    virtual int Lock( int )                                                  zPureCall;
    virtual int Unlock()                                                     zPureCall;
    virtual int SetTextureInfo( zCTextureInfo const& )                       zPureCall;
    virtual void* GetPaletteBuffer()                                         zPureCall;
    virtual int GetTextureBuffer( int, void*&, int& )                        zPureCall;
    virtual zCTextureInfo GetTextureInfo()                                   zPureCall;
    virtual int CopyPaletteDataTo( void* )                                   zPureCall;
    virtual int CopyTextureDataTo( int, void*, int )                         zPureCall;
    virtual int HasAlpha()                                                   zPureCall;
    virtual zVEC4 GetRGBAAtTexel( float, float )                             zCall( 0x005F8340 );
  };

  class zCTextureConvert : public zCTextureExchange {
  public:

    zCTextureConvert() {}
    int LoadFromFileFormat( zSTRING const& )                  zCall( 0x005F4F30 );
    int SaveToFileFormat( zSTRING const& )                    zCall( 0x005F5010 );
    int LoadFromFileFormat( zFILE&, zCTextureFileFormat* )    zCall( 0x005F50F0 );
    int SaveToFileFormat( zFILE&, zCTextureFileFormat* )      zCall( 0x005F5120 );
    int SaveInternal( zFILE& )                                zCall( 0x005F5150 );
    int LoadInternal( zFILE& )                                zCall( 0x005F51E0 );
    void ConvertToNewFormat( zTRnd_TextureFormat const& )     zCall( 0x005F5270 );
    void ConvertToNewSize( int, int )                         zCall( 0x005F52A0 );
    void GenerateMipMaps()                                    zCall( 0x005F5390 );
    static int CalcNumMipMaps( unsigned long, unsigned long ) zCall( 0x005F53E0 );
    static void CorrectAspectRatio( int&, int& )              zCall( 0x005F5410 );
    static void CorrectPow2( int&, int& )                     zCall( 0x005F5490 );
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

    void zCTexture_OnInit()                                                                        zCall( 0x005F3390 );
    zCTexture()                                                                                    zInit( zCTexture_OnInit() );
    void InitValues()                                                                              zCall( 0x005F3470 );
    int IsLightmap() const                                                                         zCall( 0x005F3570 );
    zCTexture* GetAniTexture()                                                                     zCall( 0x005F35C0 );
    void AddAniTex( int, zCTexture* )                                                              zCall( 0x005F3620 );
    void PrecacheTexAniFrames( float )                                                             zCall( 0x005F3660 );
    void ForceConvertAndReloadTexture()                                                            zCall( 0x005F6170 );
    int LoadAndConvertInternal( zFILE& )                                                           zCall( 0x005F64C0 );
    int SaveAndConvertInternal( zFILE& )                                                           zCall( 0x005F6840 );
    int CacheInNamed( zSTRING const* )                                                             zCall( 0x005F69E0 );
    int IsTextureTileBaseSlice() const                                                             zCall( 0x005F73F0 );
    int CreateTextureTile( zCTextureExchange* )                                                    zCall( 0x005F7420 );
    void GetPixelSize( int&, int& )                                                                zCall( 0x005F7C10 );
    static zCTexture* SearchName( zSTRING& )                                                       zCall( 0x005F3550 );
    static zCTexture* Load( zSTRING&, int )                                                        zCall( 0x005F36A0 );
    static zCTexture* LoadSingle( zSTRING&, int )                                                  zCall( 0x005F4360 );
    static int Exists( zSTRING& )                                                                  zCall( 0x005F4510 );
    static void AutoDetectRendererTexScale()                                                       zCall( 0x005F46E0 );
    static void RefreshTexMaxSize( int )                                                           zCall( 0x005F4EA0 );
    static int ConvertTexture( zSTRING const& )                                                    zCall( 0x005F59F0 );
    static zTRnd_TextureFormat CalcNextBestTexFormat( zTRnd_TextureFormat )                        zCall( 0x005F6240 );
    static void CalcDesiredBPP( zSTRING const*, zTTexFileDesiredBPP&, zTRnd_TextureFormat&, int& ) zCall( 0x005F6340 );
    static void ScanConvertTextures( zSTRING )                                                     zCall( 0x005F7F40 );
    static void operator delete( void* )                                                           zCall( 0x006536B0 );
    /* for zCResource num : 11*/
    virtual zCClassDef* _GetClassDef() const                                                       zCall( 0x005F3400 );
    virtual ~zCTexture()                                                                           zCall( 0x005F34A0 );
    virtual int LoadResourceData()                                                                 zCall( 0x005F54D0 );
    virtual int ReleaseResourceData()                                                              zCall( 0x005F5530 );
    virtual unsigned long GetResSizeBytes()                                                        zCall( 0x005F5590 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& )                                  zCall( 0x005F5720 );
    virtual int GetChromaKeyingEnabled() const                                                     zCall( 0x005F3420 );
    virtual void SetChromaKeyingEnabled( int )                                                     zCall( 0x005F3430 );
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
    virtual int HasAlpha()                                                                         zCall( 0x005F3410 );

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

    void zCLightMap_OnInit()                                                   zCall( 0x005F8EA0 );
    zCLightMap()                                                               zInit( zCLightMap_OnInit() );
    void SetTexture( zCTexture* )                                              zCall( 0x005F8FD0 );
    void CalcLightmapOriginUpRight( zVEC3 const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005F9010 );
    static void operator delete( void* )                                       zCall( 0x00571680 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x005F8DD0 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x005F8E90 );
    virtual ~zCLightMap()                                                      zCall( 0x005F8F60 );
  };

  class zCTextureFileHandler : public zCScanDirFileHandler {
  public:

    zCTextureFileHandler() {}
    virtual ~zCTextureFileHandler()                                    zCall( 0x00424C10 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005F7C40 );
  };

} // namespace Gothic_II_Addon

#endif // __ZTEXTURE_H__VER3__