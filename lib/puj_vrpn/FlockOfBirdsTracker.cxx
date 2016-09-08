#include <puj_vrpn/FlockOfBirdsTracker.h>

// -------------------------------------------------------------------------
namespace puj_vrpn
{
  puj_vrpn_Callback_Macro( FlockOfBirdsTracker, Tracker, vrpn_TRACKERCB );

} // ecapseman

// -------------------------------------------------------------------------
puj_vrpn::FlockOfBirdsTracker::
FlockOfBirdsTracker( unsigned int B )
  : Superclass( B )
{
}

// -------------------------------------------------------------------------
puj_vrpn::FlockOfBirdsTracker::
~FlockOfBirdsTracker( )
{
}

// -------------------------------------------------------------------------
void puj_vrpn::FlockOfBirdsTracker::
linkHandlers( )
{
  this->m_Device.Tracker->register_change_handler(
    this,
    puj_vrpn_Callback_Name_Macro( FlockOfBirdsTracker, Tracker )
    );
}

// eof - $RCSfile$
