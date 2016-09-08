#ifndef __puj_vrpn__FlockOfBirdsTracker__h__
#define __puj_vrpn__FlockOfBirdsTracker__h__

#include <puj_vrpn/Device.h>

namespace puj_vrpn
{
  /**
   */
  class puj_vrpn_EXPORT FlockOfBirdsTracker_State
  {
  public:
    unsigned int Id;
    float Position[ 3 ];
    float Rotation[ 4 ];

    void setTracker(
      unsigned int id,
      float px, float py, float pz,
      float qx, float qy, float qz, float qw
      )
    {
      this->Id = id;

      this->Position[ 0 ] = px;
      this->Position[ 1 ] = py;
      this->Position[ 2 ] = pz;

      this->Rotation[ 0 ] = qx;
      this->Rotation[ 1 ] = qy;
      this->Rotation[ 2 ] = qz;
      this->Rotation[ 3 ] = qw;
    }
    void clear( )
    {
      this->Id = 0;

      this->Position[ 0 ] = float( 0 );
      this->Position[ 1 ] = float( 0 );
      this->Position[ 2 ] = float( 0 );

      this->Rotation[ 0 ] = float( 0 );
      this->Rotation[ 1 ] = float( 0 );
      this->Rotation[ 2 ] = float( 0 );
      this->Rotation[ 3 ] = float( 0 );
    }
  };

  /**
   */
  class puj_vrpn_EXPORT FlockOfBirdsTracker
    : public Device< FlockOfBirdsTracker_State >
  {
  public:
    typedef FlockOfBirdsTracker                 Self;
    typedef Device< FlockOfBirdsTracker_State > Superclass;

  public:
    explicit FlockOfBirdsTracker( unsigned int B = 32 );
    virtual ~FlockOfBirdsTracker( );

  protected:
    virtual void linkHandlers( );
  };

} // ecapseman

#endif // __puj_vrpn__FlockOfBirdsTracker__h__

// eof - $RCSfile$
