#include <puj_vrpn/Glove5dt14.h>

// -------------------------------------------------------------------------
namespace puj_vrpn
{
  puj_vrpn_Callback_Macro( Glove5dt14, Analog, vrpn_ANALOGCB );

} // ecapseman

// -------------------------------------------------------------------------
puj_vrpn::Glove5dt14::
Glove5dt14( unsigned int B )
  : Superclass( B )
{
}

// -------------------------------------------------------------------------
puj_vrpn::Glove5dt14::
~Glove5dt14( )
{
}

// -------------------------------------------------------------------------
void puj_vrpn::Glove5dt14::
linkHandlers( )
{
  this->m_Device.Analog->register_change_handler(
    this,
    puj_vrpn_Callback_Name_Macro( Glove5dt14, Analog )
    );
}

// eof - $RCSfile$
