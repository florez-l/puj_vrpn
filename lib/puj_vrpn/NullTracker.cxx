#include <puj_vrpn/NullTracker.h>

// -------------------------------------------------------------------------
namespace puj_vrpn
{
  puj_vrpn_Callback_Macro( NullTracker, Tracker, vrpn_TRACKERCB );

} // ecapseman

// -------------------------------------------------------------------------
puj_vrpn::NullTracker::
NullTracker( unsigned int B )
  : Superclass( B )
{
}

// -------------------------------------------------------------------------
puj_vrpn::NullTracker::
~NullTracker( )
{
}

// -------------------------------------------------------------------------
void puj_vrpn::NullTracker::
linkHandlers( )
{
  this->m_Device.Tracker->register_change_handler(
    this,
    puj_vrpn_Callback_Name_Macro( NullTracker, Tracker )
    );
}

// eof - $RCSfile$
