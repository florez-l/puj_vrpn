#ifndef __puj_vrpn__Glove5dt14__h__
#define __puj_vrpn__Glove5dt14__h__

#include <puj_vrpn/Device.h>

namespace puj_vrpn
{
  /**
   */
  class puj_vrpn_EXPORT Glove5dt14_State
  {
  public:
    float Channel[ 14 ];
    void setAnalog( const vrpn_ANALOGCB* a )
    {
      for( unsigned int i = 0; i < 14; i++ )
        this->Channel[ i ] = a->channel[ i ];
    }
    void clear( )
    {
      for( unsigned int i = 0; i < 14; i++ )
        this->Channel[ i ] = float( 0 );
    }
  };

  /**
   */
  class puj_vrpn_EXPORT Glove5dt14
    : public Device< Glove5dt14_State >
  {
  public:
    typedef Glove5dt14                 Self;
    typedef Device< Glove5dt14_State > Superclass;

  public:
    explicit Glove5dt14( unsigned int B = 32 );
    virtual ~Glove5dt14( );

  protected:
    virtual void linkHandlers( );
  };

} // ecapseman

#endif // __puj_vrpn__Glove5dt14__h__

// eof - $RCSfile$
