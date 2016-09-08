#include <iostream>
#include <puj_vrpn/NullTracker.h>

int main( int argc, char* argv[] )
{
  if( argc < 2 )
  {
    std::cerr << "Usage: " << argv[ 0 ] << " tracker@host" << std::endl;
    return( 1 );

  } // fi

  puj_vrpn::NullTracker tracker;
  tracker.connect( argv[ 1 ] );

  puj_vrpn::NullTracker_State tracker_state;
  while( true )
  {
    tracker_state = tracker.capture( );

    std::cout
      << "Id: " << tracker_state.Id
      << " | Position: ("
      << tracker_state.Position[ 0 ] << ", "
      << tracker_state.Position[ 1 ] << ", "
      << tracker_state.Position[ 2 ] << ")"
      << " | Rotation: ["
      << tracker_state.Rotation[ 0 ] << ", "
      << tracker_state.Rotation[ 1 ] << ", "
      << tracker_state.Rotation[ 2 ] << ", "
      << tracker_state.Rotation[ 3 ] << "]"
      << std::endl;

  } // elihw
  return( 0 );
}

// eof - $RCSfile$
