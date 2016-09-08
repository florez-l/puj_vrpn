#ifndef __puj_vrpn__WiiMote__h__
#define __puj_vrpn__WiiMote__h__

#include <puj_vrpn/Device.h>

namespace puj_vrpn
{
  /**
   * # Server configuration:
   * # Nintendo Wii Remote Controller
   * # char name_of_this_device[]
   * # int userIndex (1 for "Player 1", 2 for "Player 2", etc.)
   * # int useMotionSensing
   * # int useIR
   * # int reorderButtons (set to make button ids somewhat more sensible)
   * # char bluetooth_address[] (optional, only supported on Linux -
   *                             upper case, include colons)
   *
   * WiiMote  WiiMote0 1 1 1 1
   *
   */
  class puj_vrpn_EXPORT WiiMote_State
  {
  public:
    enum
    {
      NumberOfChannels = 96,
      NumberOfButtons = 64
    };

    /*
     * The buttons are as read from the bit-fields of the primary controller
     * (bits 0-15) and then a second set for any extended controller (nunchuck
     * bits 16-31), (classic controller bits 32-47), (guitar hero 3 bits
     * 48-63).
     *
     * If you enable "reorderButtons" by setting it to 1, the buttons on the
     * Wiimote itself are re-ordered to be reported as follows:
     *
     * PushedButtons[0] = Home
     * PushedButtons[1] = "1"
     * PushedButtons[2] = "2"
     * PushedButtons[3] = "A"
     * PushedButtons[4] = "B"
     * PushedButtons[5] = "-"
     * PushedButtons[6] = "+"
     * PushedButtons[7] = direction pad: left
     * PushedButtons[8] = direction pad: right
     * PushedButtons[9] = direction pad: down
     * PushedButtons[10] = direction pad: up
     * PushedButtons[11] = WIIMOTE_BUTTON_ZACCEL_BIT4
     * PushedButtons[12] = WIIMOTE_BUTTON_ZACCEL_BIT5
     * PushedButtons[13] = WIIMOTE_BUTTON_ZACCEL_BIT6
     * PushedButtons[14] = WIIMOTE_BUTTON_ZACCEL_BIT7
     * PushedButtons[15] = WIIMOTE_BUTTON_UNKNOWN
     */
    enum Buttons
    {
      ButtonHome = 0,
      Button1,
      Button2,
      ButtonA,
      ButtonB,
      ButtonMinus,
      ButtonPlus,
      ButtonLeft,
      ButtonRight,
      ButtonDown,
      ButtonUp,
      ButtonZACCEL_BIT4,
      ButtonZACCEL_BIT5,
      ButtonZACCEL_BIT6,
      ButtonZACCEL_BIT7,
      ButtonUNKNOWN
    };
    unsigned long PushedButtons;
    puj_vrpn_PushedButton( ButtonHome );
    puj_vrpn_PushedButton( Button1 );
    puj_vrpn_PushedButton( Button2 );
    puj_vrpn_PushedButton( ButtonA );
    puj_vrpn_PushedButton( ButtonB );
    puj_vrpn_PushedButton( ButtonMinus );
    puj_vrpn_PushedButton( ButtonPlus );
    puj_vrpn_PushedButton( ButtonLeft );
    puj_vrpn_PushedButton( ButtonRight );
    puj_vrpn_PushedButton( ButtonDown );
    puj_vrpn_PushedButton( ButtonUp );
    puj_vrpn_PushedButton( ButtonZACCEL_BIT4 );
    puj_vrpn_PushedButton( ButtonZACCEL_BIT5 );
    puj_vrpn_PushedButton( ButtonZACCEL_BIT6 );
    puj_vrpn_PushedButton( ButtonZACCEL_BIT7 );
    puj_vrpn_PushedButton( ButtonUNKNOWN );

    /*
     * Channel[0] = battery level (0-1)
     * Channel[1] = gravity X vector calculation (1 = Earth gravity)
     * Channel[2] = gravity Y vector calculation (1 = Earth gravity)
     * Channel[3] = gravity Z vector calculation (1 = Earth gravity)
     * Channel[4] = X of first sensor spot (0-1023, -1 if not seen)
     * Channel[5] = Y of first sensor spot (0-767, -1 if not seen)
     * Channel[6] = size of first sensor spot (0-15, -1 if not seen)
     * Channel[7] = X of second sensor spot (0-1023, -1 if not seen)
     * Channel[9] = Y of second sensor spot (0-767, -1 if not seen)
     * Channel[9] = size of second sensor spot (0-15, -1 if not seen)
     * Channel[10] = X of third sensor spot (0-1023, -1 if not seen)
     * Channel[11] = Y of third sensor spot (0-767, -1 if not seen)
     * Channel[12] = size of third sensor spot (0-15, -1 if not seen)
     * Channel[13] = X of fourth sensor spot (0-1023, -1 if not seen)
     * Channel[14] = Y of fourth sensor spot (0-767, -1 if not seen)
     * Channel[15] = size of fourth sensor spot (0-15, -1 if not seen)
     *               and on the secondary controllers (skipping values to
     *               leave room for expansion)
     * Channel[16] = nunchuck gravity X vector
     * Channel[17] = nunchuck gravity Y vector
     * Channel[18] = nunchuck gravity Z vector
     * Channel[19] = nunchuck joystick angle
     * Channel[20] = nunchuck joystick magnitude
     *
     * Channel[32] = classic L button
     * Channel[33] = classic R button
     * Channel[34] = classic L joystick angle
     * Channel[35] = classic L joystick magnitude
     * Channel[36] = classic R joystick angle
     * Channel[37] = classic R joystick magnitude
     *
     * Channel[48] = guitar hero whammy bar
     * Channel[49] = guitar hero joystick angle
     * Channel[50] = guitar hero joystick magnitude
     *
     * Balance board data: (requires WiiUse 0.13 or newer, preferably 0.14
     * or newer)
     * Channel[64] = Balance board: top-left sensor, kg
     * Channel[65] = Balance board: top-right sensor, kg
     * Channel[66] = Balance board: bottom-left sensor, kg
     * Channel[67] = Balance board: bottom-right sensor, kg
     * Channel[68] = Balance board: total mass, kg
     * Channel[69] = Balance board: center of gravity x, in [-1, 1]
     * Channel[70] = Balance board: center of gravity y, in [-1, 1]
     */
    enum ChannelName
    {
      ChannelBattery = 0,
      ChannelGravityX,
      ChannelGravityY,
      ChannelGravityZ,
      ChannelX1StSensor,
      ChannelY1StSensor,
      ChannelSize1StSensor,
      ChannelX2ndSensor,
      ChannelY2ndSensor,
      ChannelSize2ndSensor,
      ChannelX3rdSensor,
      ChannelY3rdSensor,
      ChannelSize3rdSensor,
      ChannelX4thSensor,
      ChannelY4thSensor,
      ChannelSize4thSensor,
      ChannelNunchuckGravityX,
      ChannelNunchuckGravityY,
      ChannelNunchuckGravityZ,
      ChannelNunchuckAngle,
      ChannelNunchuckMagnitude,
      ChannelClassicLButton,
      ChannelClassicRButton,
      ChannelClassicLMagnitude,
      ChannelClassicRAngle,
      ChannelClassicRMagnitude,
      ChannelGuitarBar,
      ChannelGuitarAngle,
      ChannelGuitarMagnitude,
      ChannelBalanceBoardTopLeft,
      ChannelBalanceBoardTopRight,
      ChannelBalanceBoardBottomLeft,
      ChannelBalanceBoardBottomRight,
      ChannelBalanceBoardTotalMass,
      ChannelBalanceBoardGCX,
      ChannelBalanceBoardGCY
    };
    vrpn_float64 Channel[ NumberOfChannels ];
    void setAnalog( const vrpn_ANALOGCB* a )
    {
      std::memcpy(
        this->Channel, a->channel, NumberOfChannels * sizeof( vrpn_float64 )
        );
    }
    void clear( )
    {
      this->PushedButtons = 0;
      for( unsigned int i = 0; i < NumberOfChannels; i++ )
        this->Channel[ i ] = float( 0 );
    }
  };

  /**
   */
  class puj_vrpn_EXPORT WiiMote
    : public Device< WiiMote_State >
  {
  public:
    typedef WiiMote                 Self;
    typedef Device< WiiMote_State > Superclass;

  public:
    explicit WiiMote( unsigned int B = 32 );
    virtual ~WiiMote( );

  protected:
    virtual void linkHandlers( );
  };

} // ecapseman

#endif // __puj_vrpn__WiiMote__h__

// eof - $RCSfile$

