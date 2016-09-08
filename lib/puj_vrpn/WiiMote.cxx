#include <puj_vrpn/WiiMote.h>

// -------------------------------------------------------------------------
namespace puj_vrpn
{
  puj_vrpn_Callback_Macro( WiiMote, Analog, vrpn_ANALOGCB );
  puj_vrpn_Callback_Macro( WiiMote, Button, vrpn_BUTTONCB );

} // ecapseman

// -------------------------------------------------------------------------
puj_vrpn::WiiMote::
WiiMote( unsigned int B )
  : Superclass( B, puj_vrpn::WiiMote_State::NumberOfButtons )
{
}

// -------------------------------------------------------------------------
puj_vrpn::WiiMote::
~WiiMote( )
{
}

// -------------------------------------------------------------------------
void puj_vrpn::WiiMote::
linkHandlers( )
{
  this->m_Device.Analog->register_change_handler(
    this,
    puj_vrpn_Callback_Name_Macro( WiiMote, Analog )
    );
  this->m_Device.Button->register_change_handler(
    this,
    puj_vrpn_Callback_Name_Macro( WiiMote, Button )
    );
}

// eof - $RCSfile$
