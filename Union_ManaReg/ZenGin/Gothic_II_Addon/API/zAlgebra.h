// Supported with union (c) 2018 Union team

#ifndef __ZALGEBRA_H__VER3__
#define __ZALGEBRA_H__VER3__

namespace Gothic_II_Addon {
  const double PI     = 3.14159265359;
  const double RAD    = PI / 180.0f;
  const double DEGREE = 180.0 / PI;

  const float RAD90  = 90.0f  / DEGREE;
  const float RAD180 = 180.0f / DEGREE;
  const float RAD270 = 270.0f / DEGREE;

  const float AVERAGE_SMOOTH_FRAME_TIME = 0.025f;

  enum {
    VX,
    VY,
    VZ,
    VW
  };

  enum {
    VA,
    VB,
    VC,
    VD
  };

  enum {
    PA,
    PB,
    PC,
    PD
  };

  enum {
    RED,
    GREEN,
    BLUE
  };

  enum {
    KA,
    KD,
    KS,
    ES
  };

  class zVEC2 {
  public:
    float n[2];

    zVEC2()
    {
      n[0] = 0;
      n[1] = 0;
    }

    zVEC2( const float& a0 )
    {
      n[0] = a0;
      n[1] = a0;
    }

    zVEC2( const float& a0, const float& a1 )
    {
      n[0] = a0;
      n[1] = a1;
    }

    zVEC2( const zVEC2& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[0];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return n[0] * n[0] + n[1] * n[1];
    }

    zVEC2& Normalize()
    {
      float len = Length();
      return len != 0.0f ? *this /= Length() : *this = 0.0f;
    }

    float Distance( const zVEC2& a0 ) const
    {
      return ( a0 - *this ).Length();
    }

    zVEC2& operator += ( const zVEC2& a0 )
    {
      n[0] += a0[0];
      n[1] += a0[1];
      return *this;
    }

    zVEC2& operator -= ( const zVEC2& a0 )
    {
      n[0] -= a0[0];
      n[1] -= a0[1];
      return *this;
    }

    zVEC2& operator *= ( const zVEC2& a0 )
    {
      n[0] *= a0[0];
      n[1] *= a0[1];
      return *this;
    }

    zVEC2& operator /= ( const zVEC2& a0 )
    {
      n[0] /= a0[0];
      n[1] /= a0[1];
      return *this;
    }

    zVEC2& operator = ( const zVEC2& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      return *this;
    }

    bool32 operator == ( const zVEC2& a0 ) const
    {
      return n[0] == a0[0] && n[1] == a0[1];
    }

    bool32 operator != ( const zVEC2& a0 ) const
    {
      return n[0] != a0[0] || n[1] != a0[1];
    }

    zVEC2 operator + ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) += a0;
    }

    zVEC2 operator - ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) -= a0;
    }

    zVEC2 operator * ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) *= a0;
    }

    zVEC2 operator / ( const zVEC2& a0 ) const
    {
      return zVEC2( *this ) /= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return n[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return n[index];
    }
  };

  class zVEC3 {
  public:
    float n[3];

    zVEC3()
    {
      n[0] = 0;
      n[1] = 0;
      n[2] = 0;
    }

    zVEC3( const float& a0 )
    {
      n[0] = a0;
      n[1] = a0;
      n[2] = a0;
    }

    zVEC3( const float& a0, const float& a1, const float& a2 )
    {
      n[0] = a0;
      n[1] = a1;
      n[2] = a2;
    }

    zVEC3( const zVEC3& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
    }

    zVEC3& Normalize()
    {
      float len = Length();
      return len != 0.0f ? *this /= Length() : *this = 0.0f;
    }

    float Distance( const zVEC3& a0 ) const
    {
      return ( a0 - *this ).Length();
    }

    float Dot( const zVEC3& a0 ) const
    {
      return n[VX] * a0.n[VX] + n[VY] * a0.n[VY] + n[VZ] * a0.n[VZ];
    }

    zVEC3 Cross( const zVEC3& a0 ) const
    {
      return zVEC3(
        n[VY] * a0.n[VZ] - n[VZ] * a0.n[VY],
        n[VZ] * a0.n[VX] - n[VX] * a0.n[VZ],
        n[VX] * a0.n[VY] - n[VY] * a0.n[VX] );
    }

    zVEC3& operator += ( const zVEC3& a0 )
    {
      n[0] += a0[0];
      n[1] += a0[1];
      n[2] += a0[2];
      return *this;
    }

    zVEC3& operator -= ( const zVEC3& a0 )
    {
      n[0] -= a0[0];
      n[1] -= a0[1];
      n[2] -= a0[2];
      return *this;
    }

    zVEC3& operator *= ( const zVEC3& a0 )
    {
      n[0] *= a0[0];
      n[1] *= a0[1];
      n[2] *= a0[2];
      return *this;
    }

    zVEC3& operator /= ( const zVEC3& a0 )
    {
      n[0] /= a0[0];
      n[1] /= a0[1];
      n[2] /= a0[2];
      return *this;
    }

    zVEC3& operator =  ( const zVEC3& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
      return *this;
    }

    bool32 operator == ( const zVEC3& a0 ) const
    {
      return n[0] == a0[0] && n[1] == a0[1] && n[2] == a0[2];
    }

    bool32 operator != ( const zVEC3& a0 ) const
    {
      return n[0] != a0[0] || n[1] != a0[1] || n[2] != a0[2];
    }

    zVEC3 operator +  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) += a0;
    }

    zVEC3  operator -  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) -= a0;
    }

    zVEC3  operator *  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) *= a0;
    }

    zVEC3  operator /  ( const zVEC3& a0 ) const
    {
      return zVEC3( *this ) /= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return n[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return n[index];
    }

    float GetAngleXZ() {
      CalcAngle(n[0], n[2]);
    }

    float GetAngleXY() {
      CalcAngle(n[0], n[1]);
    }

    float GetAngleYZ() {
      CalcAngle(n[1], n[2]);
    }

    zVEC3& RotateXZ( const float& rad ) {
      RotAngle(n[0], n[2], XZ);
    }

    zVEC3& RotateXY( const float& rad ) {
      RotAngle(n[0], n[1], XY);
    }

    zVEC3& RotateYZ( const float& rad ) {
      RotAngle(n[1], n[2], YZ);
    }
  };

  class zVEC4 {
  public:
    float n[4];

    zVEC4()
    {
      n[0] = 0;
      n[1] = 0;
      n[2] = 0;
      n[3] = 0;
    }

    zVEC4( const float& a0 )
    {
      n[0] = a0;
      n[1] = a0;
      n[2] = a0;
      n[3] = a0;
    }

    zVEC4( const float& a0, const float& a1, const float& a2, const float& a3 )
    {
      n[0] = a0;
      n[1] = a1;
      n[2] = a2;
      n[3] = a3;
    }

    zVEC4( const zVEC4& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
      n[3] = a0[3];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return n[0] * n[0] + n[1] * n[1] + n[2] * n[2] + n[3] * n[3];
    }

    zVEC4& Normalize()
    {
      float len = Length();
      return len != 0.0f ? *this /= Length() : *this = 0.0f;
    }

    float Distance( const zVEC4& a0 ) const
    {
      return ( a0 - *this ).Length();
    }

    float Dot( const zVEC4& a0 ) const
    {
      return n[VX] * a0.n[VX] + n[VY] * a0.n[VY] + n[VZ] * a0.n[VZ] + n[VW] * a0.n[VW];
    }

    zVEC3 Cross( const zVEC4& a0 ) const
    {
      return zVEC3(
        n[VY] * a0.n[VZ] - n[VZ] * a0.n[VY],
        n[VZ] * a0.n[VX] - n[VX] * a0.n[VZ],
        n[VX] * a0.n[VY] - n[VY] * a0.n[VX] );
    }

    zVEC4& operator += ( const zVEC4& a0 )
    {
      n[0] += a0[0];
      n[1] += a0[1];
      n[2] += a0[2];
      n[3] += a0[3];
      return *this;
    }

    zVEC4& operator -= ( const zVEC4& a0 )
    {
      n[0] -= a0[0];
      n[1] -= a0[1];
      n[2] -= a0[2];
      n[3] -= a0[3];
      return *this;
    }

    zVEC4& operator *= ( const zVEC4& a0 )
    {
      n[0] *= a0[0];
      n[1] *= a0[1];
      n[2] *= a0[2];
      n[3] *= a0[3];
      return *this;
    }

    zVEC4& operator /= ( const zVEC4& a0 )
    {
      n[0] /= a0[0];
      n[1] /= a0[1];
      n[2] /= a0[2];
      n[3] /= a0[3];
      return *this;
    }

    zVEC4& operator =  ( const zVEC4& a0 )
    {
      n[0] = a0[0];
      n[1] = a0[1];
      n[2] = a0[2];
      n[3] = a0[3];
      return *this;
    }

    bool32 operator == ( const zVEC4& a0 ) const
    {
      return n[0] == a0[0] && n[1] == a0[1] && n[2] == a0[2] && n[3] == a0[3];
    }

    bool32 operator != ( const zVEC4& a0 ) const
    {
      return n[0] != a0[0] || n[1] != a0[1] || n[2] != a0[2] || n[3] != a0[3];
    }

    zVEC4 operator + ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) += a0;
    }

    zVEC4 operator - ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) -= a0;
    }

    zVEC4 operator * ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) *= a0;
    }

    zVEC4 operator / ( const zVEC4& a0 ) const
    {
      return zVEC4( *this ) /= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return n[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return n[index];
    }
  };

  class zMAT3 {
  public:
    zVEC3 v[3];

    zMAT3()
    {
      v[0] = 0.0f;
      v[1] = 0.0f;
      v[2] = 0.0f;
    }

    zMAT3( const zVEC3& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
    }

    zMAT3( const zVEC3& a0, const zVEC3& a1, const zVEC3& a2 )
    {
      v[0] = a0;
      v[1] = a1;
      v[2] = a2;
    }

    zMAT3( const float& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
    }

    zMAT3( const zMAT3& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
    }

    static const zMAT3& GetIdentity()
    {
      return *(zMAT3*)0x008D4628;
    }

    void MakeIdentity()
    {
      *this = GetIdentity();
    }

    void MakeZero()
    {
      v[0] = 0.0f;
      v[1] = 0.0f;
      v[2] = 0.0f;
    }

    zMAT3 Transpose() const
    {
      return zMAT3(
        zVEC3( v[0][0], v[1][0], v[2][0] ),
        zVEC3( v[0][1], v[1][1], v[2][1] ),
        zVEC3( v[0][2], v[1][2], v[2][2] ) );
    }

    zMAT3 Inverse( float* det = Null )
    {
      zVEC3 vec( 
        v[VY][VY] * v[VZ][VZ] - v[VY][VZ] * v[VZ][VY],
        v[VY][VZ] * v[VZ][VX] - v[VY][VX] * v[VZ][VZ],
        v[VY][VX] * v[VZ][VY] - v[VY][VY] * v[VZ][VX] );
      float dot = v->Dot( vec );
      if( det )
      {
        *det = dot;
      }
      float div = 1.0f / dot;
      return zMAT3(
        zVEC3( vec[VX] * div,
              ( v[VX][VZ] * v[VZ][VY] - v[VX][VY] * v[VZ][VZ] ) * div,
              ( v[VX][VY] * v[VY][VZ] - v[VX][VZ] * v[VY][VY] ) * div ),
        zVEC3( vec[VY] * div,
              ( v[VX][VX] * v[VZ][VZ] - v[VX][VZ] * v[VZ][VX] ) * div,
              ( v[VX][VZ] * v[VY][VX] - v[VX][VX] * v[VY][VZ] ) * div ),
        zVEC3( vec[VZ] * div,
              ( v[VX][VY] * v[VZ][VX] - v[VX][VX] * v[VZ][VY] ) * div,
              ( v[VX][VX] * v[VY][VY] - v[VX][VY] * v[VY][VX] ) * div ) );
    }

    zVEC3 GetUpVector() const
    {
      return zVEC3( v[0][1], v[1][1], v[2][1] );
    }

    zVEC3 GetRightVector() const
    {
      return zVEC3( v[0][0], v[1][0], v[2][0] );
    }

    zVEC3 GetAtVector() const
    {
      return zVEC3( v[0][2], v[1][2], v[2][2] );
    }
    void SetUpVector( const zVEC3& a0 )
    {
      v[0][2] = a0.n[VX];
      v[1][2] = a0.n[VY];
      v[2][2] = a0.n[VZ];
    }

    void SetRightVector( const zVEC3& a0 )
    {
      v[0][1] = a0.n[VX];
      v[1][1] = a0.n[VY];
      v[2][1] = a0.n[VZ];
    }

    void SetAtVector( const zVEC3& a0 )
    {
      v[0][0] = a0.n[VX];
      v[1][0] = a0.n[VY];
      v[2][0] = a0.n[VZ];
    }

    zMAT3& operator += ( const zMAT3& a0 )
    {
      v[0] += a0[0];
      v[1] += a0[1];
      v[2] += a0[2];
      v[3] += a0[3];
      return *this;
    }

    zMAT3& operator -= ( const zMAT3& a0 )
    {
      v[0] -= a0[0];
      v[1] -= a0[1];
      v[2] -= a0[2];
      v[3] -= a0[3];
      return *this;
    }

    zMAT3& operator *= ( const zMAT3& a0 )
    {
      v[0] *= a0[0];
      v[1] *= a0[1];
      v[2] *= a0[2];
      v[3] *= a0[3];
      return *this;
    }

    zMAT3& operator /= ( const zMAT3& a0 )
    {
      v[0] /= a0[0];
      v[1] /= a0[1];
      v[2] /= a0[2];
      v[3] /= a0[3];
      return *this;
    }

    zMAT3& operator =  ( const zMAT3& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
      v[3] = a0[3];
      return *this;
    }

    bool32 operator == ( const zMAT3& a0 ) const
    {
      return v[0] == a0[0] && v[1] == a0[1] && v[2] == a0[2] && v[3] == a0[3];
    }

    bool32 operator != ( const zMAT3& a0 ) const
    {
      return v[0] != a0[0] || v[1] != a0[1] || v[2] != a0[2] || v[3] != a0[3];
    }

    zMAT3  operator + ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) += a0;
    }

    zMAT3  operator - ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) -= a0;
    }

    zMAT3  operator * ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) *= a0;
    }

    zMAT3  operator / ( const zMAT3& a0 ) const
    {
      return zMAT3( *this ) /= a0;
    }

    zVEC3& operator [] ( const uint32& index )
    {
      return v[index];
    }

    const zVEC3& operator [] ( const uint32& index ) const
    {
      return v[index];
    }

    static zMAT3& s_identity;
  };

  class zMAT4 {
  public:
    zVEC4 v[4];

    zMAT4()
    {
      v[0] = 0.0f;
      v[1] = 0.0f;
      v[2] = 0.0f;
      v[3] = 0.0f;
    }

    zMAT4( const zVEC4& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
      v[3] = a0;
    }

    zMAT4( const zVEC4& a0, const zVEC4& a1, const zVEC4& a2, const zVEC4& a3 )
    {
      v[0] = a0;
      v[1] = a1;
      v[2] = a2;
      v[3] = a3;
    }

    zMAT4( const float& a0 )
    {
      v[0] = a0;
      v[1] = a0;
      v[2] = a0;
      v[3] = a0;
    }

    zMAT4( const zMAT4& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
      v[3] = a0[3];
    }

    zMAT4 Inverse()                     zCall( 0x00515500 );
    void MakeOrthonormal()              zCall( 0x00517330 );
    zMAT3 ExtractRotation() const       zCall( 0x005171F0 );
    zVEC3 ExtractScaling() const        zCall( 0x00517170 );
    void PostRotateX( const float& a0 ) zCall( 0x00517730 );
    void PostRotateY( const float& a0 ) zCall( 0x00517780 );
    void PostRotateZ( const float& a0 ) zCall( 0x005177D0 );
    void PreScale( const zVEC3& a0 )    zCall( 0x00517840 );
    void PostScale( const zVEC3& a0 )   zCall( 0x00517820 );
    zVEC3 GetEulerAngles() const        zCall( 0x00516390 );
    void SetByEulerAngles()             zCall( 0x005163D0 );

    static const zMAT4& GetIdentity()
    {
      return *(zMAT4*)0x008D45E8;
    }

    void MakeIdentity()
    {
      *this = GetIdentity();
    }

    zMAT4 Transpose() const
    {
      return zMAT4(
        zVEC4( v[0][0], v[1][0], v[2][0], v[3][0] ),
        zVEC4( v[0][1], v[1][1], v[2][1], v[3][1] ),
        zVEC4( v[0][2], v[1][2], v[2][2], v[3][2] ),
        zVEC4( v[0][3], v[1][3], v[2][3], v[3][3] ) );
    }

    zMAT4 TransposeLinTrafo() const zCall( 0x00515180 );
    zMAT4 InverseLinTrafo() const   zCall( 0x00515340 );

    zVEC3 GetUpVector() const
    {
      return zVEC3( v[0][1], v[1][1], v[2][1] );
    }

    zVEC3 GetRightVector() const
    {
      return zVEC3( v[0][0], v[1][0], v[2][0] );
    }

    zVEC3 GetAtVector() const
    {
      return zVEC3( v[0][2], v[1][2], v[2][2] );
    }

    void SetUpVector( const zVEC3& a0 )
    {
      v[0][2] = a0.n[VX];
      v[1][2] = a0.n[VY];
      v[2][2] = a0.n[VZ];
    }

    void SetRightVector( const zVEC3& a0 )
    {
      v[0][1] = a0.n[VX];
      v[1][1] = a0.n[VY];
      v[2][1] = a0.n[VZ];
    }

    void SetAtVector( const zVEC3& a0 )
    {
      v[0][0] = a0.n[VX];
      v[1][0] = a0.n[VY];
      v[2][0] = a0.n[VZ];
    }

    zMAT4& Translate( const zVEC3& a0 )
    {
      v[0][3] += a0.n[VX];
      v[1][3] += a0.n[VY];
      v[2][3] += a0.n[VZ];
      return *this;
    }

    zMAT4& SetTranslation( const zVEC3& a0 )
    {
      v[0][3] = a0.n[VX];
      v[1][3] = a0.n[VY];
      v[2][3] = a0.n[VZ];
      return *this;
    }

    zVEC3 GetTranslation() const
    {
      return zVEC3( v[0][3], v[1][3], v[2][3] );
    }

    void ResetRotation()
    {
      SetRightVector( zVEC3( 1.0f, 0.0f, 0.0f ) );
      SetUpVector   ( zVEC3( 0.0f, 1.0f, 0.0f ) );
      SetAtVector   ( zVEC3( 0.0f, 0.0f, 1.0f ) );
    }

    zVEC3 Rotate( const zVEC3 & a0 )
    {
      return zVEC3(
        v[0].n[0] * a0.n[VX] + v[0].n[1] * a0.n[VY] + v[0].n[2] * a0.n[VZ],
        v[1].n[0] * a0.n[VX] + v[1].n[1] * a0.n[VY] + v[1].n[2] * a0.n[VZ],
        v[2].n[0] * a0.n[VX] + v[2].n[1] * a0.n[VY] + v[2].n[2] * a0.n[VZ]
      );
    }

    zMAT4& operator += ( const zMAT4& a0 )
    {
      v[0] += a0[0];
      v[1] += a0[1];
      v[2] += a0[2];
      v[3] += a0[3];
      return *this;
    }

    zMAT4& operator -= ( const zMAT4& a0 )
    {
      v[0] -= a0[0];
      v[1] -= a0[1];
      v[2] -= a0[2];
      v[3] -= a0[3];
      return *this;
    }

    zMAT4& operator *= ( const float& a0 )
    {
      v[0] *= a0;
      v[1] *= a0;
      v[2] *= a0;
      v[3] *= a0;
      return *this;
    }

    zMAT4& operator /= ( const float& a0 )
    {
      v[0] / a0;
      v[1] /= a0;
      v[2] /= a0;
      v[3] /= a0;
      return *this;
    }

    zMAT4& operator =  ( const zMAT4& a0 )
    {
      v[0] = a0[0];
      v[1] = a0[1];
      v[2] = a0[2];
      v[3] = a0[3];
      return *this;
    }

	#define ROWCOL( i, j )                        \
                       self[i][0] * other[0][j] + \
                       self[i][1] * other[1][j] + \
                       self[i][2] * other[2][j] + \
                       self[i][3] * other[3][j]

    zMAT4 operator * ( const zMAT4& other ) {
      zMAT4& self = *this;
      return zMAT4(
        zVEC4( ROWCOL( 0, 0 ), ROWCOL( 0, 1 ), ROWCOL( 0, 2 ), ROWCOL( 0, 3 ) ),
        zVEC4( ROWCOL( 1, 0 ), ROWCOL( 1, 1 ), ROWCOL( 1, 2 ), ROWCOL( 1, 3 ) ),
        zVEC4( ROWCOL( 2, 0 ), ROWCOL( 2, 1 ), ROWCOL( 2, 2 ), ROWCOL( 2, 3 ) ),
        zVEC4( ROWCOL( 3, 0 ), ROWCOL( 3, 1 ), ROWCOL( 3, 2 ), ROWCOL( 3, 3 ) )
      );
    }

    bool32 operator == ( const zMAT4& a0 ) const
    {
      return v[0] == a0[0] && v[1] == a0[1] && v[2] == a0[2] && v[3] == a0[3];
    }

    bool32 operator != ( const zMAT4& a0 ) const
    {
      return v[0] != a0[0] || v[1] != a0[1] || v[2] != a0[2] || v[3] != a0[3];
    }

    zMAT4 operator + ( const zMAT4& a0 ) const
    {
      return zMAT4( *this ) += a0;
    }

    zMAT4 operator - ( const zMAT4& a0 ) const
    {
      return zMAT4( *this ) -= a0;
    }

    zMAT4 operator * ( const float& a0 ) const
    {
      return zMAT4( *this ) *= a0;
    }

    zVEC3 operator * ( const zVEC3& a0 ) const
    {
      return zVEC3(
        v[0][0] * a0[VX] + v[0][1] * a0[VY] + v[0][2] * a0[VZ] + v[0][3],
        v[1][0] * a0[VX] + v[1][1] * a0[VY] + v[1][2] * a0[VZ] + v[1][3],
        v[2][0] * a0[VX] + v[2][1] * a0[VY] + v[2][2] * a0[VZ] + v[2][3]
      );
    }

    zVEC4 operator * ( const zVEC4& a0 ) const
    {
      return zVEC4(
        v[0][0] * a0[VX] + v[0][1] * a0[VY] + v[0][2] * a0[VZ] + v[0][3] * a0[VW],
        v[1][0] * a0[VX] + v[1][1] * a0[VY] + v[1][2] * a0[VZ] + v[1][3] * a0[VW],
        v[2][0] * a0[VX] + v[2][1] * a0[VY] + v[2][2] * a0[VZ] + v[2][3] * a0[VW],
        v[3][0] * a0[VX] + v[3][1] * a0[VY] + v[3][2] * a0[VZ] + v[3][3] * a0[VW]
      );
    }

    zMAT4 operator / ( const float& a0 ) const
    {
      return zMAT4( *this ) /= a0;
    }

    zVEC4& operator [] ( const uint32& index )
    {
      return v[index];
    }

    const zVEC4& operator [] ( const uint32& index ) const
    {
      return v[index];
    }

    static zMAT4& s_identity;
  };

  class zCQuat {
  public:
    float q[4];

    zCQuat()
    {
      q[VX] = 0.0f;
      q[VY] = 0.0f;
      q[VZ] = 0.0f;
      q[VW] = 1.0f;
    }

    zCQuat( const float& a0 )
    {
      q[VX] = 0.0f;
      q[VY] = 0.0f;
      q[VZ] = 0.0f;
      q[VW] = a0;
    }

    zCQuat( const float& a0, const float& a1, const float& a2, const float& a3 )
    {
      q[VX] = a0;
      q[VY] = a1;
      q[VZ] = a2;
      q[VW] = a3;
    }

    void QuatToMatrix3( zMAT3& a0 ) const                                                               zCall( 0x00518460 );
    void Matrix3ToQuat( zMAT3& a0 )                                                                     zCall( 0x00518820 );
    void QuatToMatrix4( zMAT4& a0 ) const                                                               zCall( 0x00518360 );
    void Matrix4ToQuat( zMAT4& a0 )                                                                     zCall( 0x00518560 );
    void QuatToEuler( zVEC3& a0) const                                                                  zCall( 0x00518AC0 );
    void EulerToQuat( const zVEC3& a0 )                                                                 zCall( 0x00518BE0 );
    void QuatToAxisAngle( zVEC3& a0, float& a1 ) const                                                  zCall( 0x00518C90 );
    void Slerp( const float& a0, const zCQuat a1, const zCQuat& a2 )                                    zCall( 0x00518D10 );
    void Lerp( const float& a0, const zCQuat a1, const zCQuat& a2 )                                     zCall( 0x00518EF0 );
    void Squad( const float& a0, const zCQuat a1, const zCQuat& a2, const zCQuat a3, const zCQuat& a4 ) zCall( 0x00518FF0 );

    void AxisAngleToQuat( const zVEC3& a0, const float a1 )
    {
      float half = 0.5f * a1;
      float sinh = sin( half );
      q[VW] = cos( half );
      q[VX] = a0[VX] * sinh; q[VY] = a0[VY] * sinh; q[VZ] = a0[VZ] * sinh;
    }

    void Normalize()
    {
      float len = 1.0f / Length_Sqr();
      q[VX] *= len;
      q[VY] *= len;
      q[VZ] *= len;
      q[VW] *= len;
    }

    zCQuat Inverse() const
    {
      return zCQuat( -q[VX], -q[VY], -q[VZ], q[VW] );
    }

    zCQuat InverseNormal() const
    {
      float len = 1.0f / Length_Sqr();
      return zCQuat(
        q[VX] * -len,
        q[VY] * -len,
        q[VZ] * -len,
        q[VW] *  len
      );
    }

    float Dot( const zCQuat& a0 ) const
    {
      return q[VX] * a0.q[VX] + q[VY] * a0.q[VY] + q[VZ] * a0.q[VZ] + q[VW] * a0.q[VW];
    }

    float Length() const
    {
      return sqrt( Length_Sqr() );
    }

    float Length_Sqr() const
    {
      return q[VX] * q[VX] + q[VY] * q[VY] + q[VZ] * q[VZ] + q[VW] * q[VW];
    }

    void Identity()
    {
      q[VX] = 0.0f;
      q[VY] = 0.0f;
      q[VZ] = 0.0f;
      q[VW] = 1.0f;
    }

    zCQuat& operator += ( const zCQuat& a0 )
    {
      q[VX] += a0[VX];
      q[VY] += a0[VY];
      q[VZ] += a0[VZ];
      q[VW] += a0[VW];
      return *this;
    }

    zCQuat& operator -= ( const zCQuat& a0 )
    {
      q[VX] -= a0[VX];
      q[VY] -= a0[VY];
      q[VZ] -= a0[VZ];
      q[VW] -= a0[VW];
      return *this;
    }

    zCQuat operator * ( const zCQuat& a0 )
    {
      return zCQuat( 
        q[VW] * a0[VX] + q[VX] * a0[VW] + q[VY] * a0[VZ] - q[VZ] * a0[VY],
        q[VW] * a0[VY] + q[VY] * a0[VW] + q[VZ] * a0[VX] - q[VX] * a0[VZ],
        q[VW] * a0[VZ] + q[VZ] * a0[VW] + q[VX] * a0[VY] - q[VY] * a0[VX],
        q[VW] * a0[VW] - q[VX] * a0[VX] - q[VY] * a0[VY] - q[VZ] * a0[VZ] 
      );
    }

    zCQuat& operator = ( const zCQuat& a0 )
    {
      q[VX] = a0[VX];
      q[VY] = a0[VY];
      q[VZ] = a0[VZ];
      q[VW] = a0[VW];
      return *this;
    }

    bool32 operator == ( const zCQuat& a0 ) const
    {
      return q[VX] == a0[VX] && q[VY] == a0[VY] && q[VZ] == a0[VZ] && q[VW] == a0[VW];
    }

    bool32 operator != ( const zCQuat& a0 ) const
    {
      return q[VX] != a0[VX] || q[VY] != a0[VY] || q[VZ] != a0[VZ] || q[VW] != a0[VW];
    }

    zCQuat operator + ( const zCQuat& a0 ) const
    {
      return zCQuat( *this ) += a0;
    }

    zCQuat operator - ( const zCQuat& a0 ) const
    {
      return zCQuat( *this ) -= a0;
    }

    float& operator [] ( const uint32& index )
    {
      return q[index];
    }

    const float& operator [] ( const uint32& index ) const
    {
      return q[index];
    }
  };

  struct zComplex {
    float real;
    float img;
    float mag;
    float phase;

    zComplex()  
    {
      real = 0.0f;
      img  = 0.0f;
      EmptyCache();
    };

    zComplex( const float r, const float i )
    {
      real = r;
      img  = i;
      EmptyCache();
    };

    zComplex operator=( const zComplex c )
    {
      zComplex d;
      d.real  = c.real;
      d.img   = c.img;
      d.mag   = c.mag;
      d.phase = c.phase;
      return d;
    };

    zComplex operator+( const zComplex c )
    {
      zComplex d;
      d.real += c.real;
      d.img  += c.img;
      return d;
    };

    zComplex operator*( const zComplex c )
    {
      zComplex d;
      d.real = this->real * c.real - this->img * c.img;
      d.img  = this->real * c.img  + this->img * c.real;
      return d;
    };

    void Set( const float r, const float i )
    {
      real = r;
      img  = i;
      EmptyCache();
    };

    void Get( float &r, float &i )
    {
      r = real;
      i = img;
    }

    void EmptyCache()
    {
      mag   = 0.0f;
      phase = 0.0f;
    }

    float Mag()   zCall( 0x00559BD0 );
    float Phase() zCall( 0x00559C40 );
  };

  class zCValueSmooth {
  public:
    float  fixedValue;
    float  smoothedValue;
    float  inertia;
    bool32 bSmooth;

    void zCValueSmooth_OnInit() zCall( 0x005191B0 );
    zCValueSmooth()             zInit( zCValueSmooth_OnInit() );
    void Smooth( float& )       zCall( 0x005191D0 );

    void SetIsSmooth( const bool32& a0 )
    {
      bSmooth = a0;
    }

    bool32 GetIsSmooth() const
    {
      return bSmooth;
    }

    void SetInertia( const float& a0 )
    {
      inertia = a0;
    }

    float GetInertia() const
    {
      return inertia;
    }

    void Set( const float& a0 )
    {
      fixedValue = smoothedValue = a0;
    }

    float GetFixed() const
    {
      return fixedValue;
    }

    float GetSmoothed() const
    {
      return smoothedValue;
    }
  };

  class zCVEC3Smooth {
  public:
    zVEC3  fixedValue;
    zVEC3  smoothedValue;
    float  inertia;
    bool32 bSmooth;

    void zCVEC3Smooth_OnInit() zCall( 0x00519230 );
    zCVEC3Smooth()             zInit( zCVEC3Smooth_OnInit() );
    void Smooth( zVEC3& )      zCall( 0x005192B0 );

    void SetIsSmooth( const bool32& a0 )
    {
      bSmooth = a0;
    }

    bool32 GetIsSmooth() const
    {
      return bSmooth;
    }

    void SetInertia( const float& a0 )
    {
      inertia = a0;
    }

    float GetInertia() const
    {
      return inertia;
    }

    void Set( const zVEC3& a0 )
    {
      fixedValue = smoothedValue = a0;
    }

    zVEC3 GetFixed() const
    {
      return fixedValue;
    }

    zVEC3 GetSmoothed() const
    {
      return smoothedValue;
    }
  };

} // namespace Gothic_II_Addon

#endif // __ZALGEBRA_H__VER3__