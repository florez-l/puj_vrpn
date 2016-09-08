#ifndef __puj_vrpn__Device__h__
#define __puj_vrpn__Device__h__

#include <puj_vrpn/puj_vrpn_Export.h>
#include <queue>
#include <string>

// -------------------------------------------------------------------------
#define puj_vrpn_PushedButton( b )                                      \
  bool is##b##Pushed( ) const                                           \
  { return( ( this->PushedButtons & ( 1 << b ) ) == ( 1 << b ) ); }

// -------------------------------------------------------------------------
#define puj_vrpn_Callback_Macro( name, dev, type )                      \
  void VRPN_CALLBACK puj_vrpn_Device_hnd##name##dev(                    \
    void* data, const type v                                            \
    )                                                                   \
  {                                                                     \
    name* devs = reinterpret_cast< name* >( data );                     \
    if( devs != NULL )                                                  \
      devs->hnd##dev( &v );                                             \
  }

// -------------------------------------------------------------------------
#define puj_vrpn_Callback_Name_Macro( name, dev )       \
  puj_vrpn_Device_hnd##name##dev

// -------------------------------------------------------------------------
class vrpn_Tracker_Remote;
class vrpn_Button_Remote;
class vrpn_Analog_Remote;
class vrpn_Dial_Remote;
class vrpn_Text_Receiver;
namespace boost
{
  class mutex;
  class thread;
}

// -------------------------------------------------------------------------
namespace puj_vrpn
{
  /**
   */
  class DeviceBase
  {
  public:
    explicit DeviceBase( unsigned int B = 32, unsigned short N = 0 ) { }
    virtual ~DeviceBase( ) { }

    virtual bool connect( const std::string& url ) = 0;
    virtual void disconnect( ) = 0;
    virtual bool isBufferFull( ) const = 0;
    virtual void clearBuffer( ) = 0;
  };

  /**
   */
  template< class _TState >
  class Device
    : public DeviceBase
  {
  public:
    typedef Device     Self;
    typedef DeviceBase Superclass;

  protected:
    typedef std::queue< _TState > TBuffer;
    struct TVRPNDevice
    {
      std::string          Name;
      vrpn_Tracker_Remote* Tracker;
      vrpn_Button_Remote*  Button;
      vrpn_Analog_Remote*  Analog;
      vrpn_Dial_Remote*    Dial;
      vrpn_Text_Receiver*  Text;
    };

  public:
    explicit Device( unsigned int B = 32, unsigned short N = 0 );
    virtual ~Device( );

    bool connect( const std::string& url );
    void disconnect( );

    virtual const _TState& capture( ) const;
    TBuffer& buffer( );
    bool isBufferFull( ) const;
    void clearBuffer( );

  protected:
    void killThread( );
    void createThread( );
    bool updateThread( );
    bool update( );

    virtual void linkHandlers( ) = 0;

  public:
    /*
     * WARNING: do not call these methods by yourself, these are just
     *          wrappers.
     */
    void hndAnalog( const void* data );
    void hndButton( const void* data );
    void hndTracker( const void* data );

  protected:
    boost::mutex*  m_Mutex;
    boost::thread* m_Thread;
    volatile bool  m_ThreadRunning;

    TVRPNDevice     m_Device;
    mutable _TState m_CurrentState;
    TBuffer         m_Buffer;
    unsigned int    m_MaxBufferSize;

    unsigned long* m_ButtonMasks;
  };

} // ecapseman

#include <puj_vrpn/Device.hxx>

#endif // __puj_vrpn__Device__h__

// eof - $RCSfile$

