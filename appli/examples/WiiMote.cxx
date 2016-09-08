#include <iostream>
#include <puj_vrpn/WiiMote.h>

int main( int argc, char* argv[] )
{
  if( argc < 2 )
  {
    std::cerr << "Usage: " << argv[ 0 ] << " wiimote@host" << std::endl;
    return( 1 );

  } // fi

  puj_vrpn::WiiMote wii;
  wii.connect( argv[ 1 ] );

  puj_vrpn::WiiMote_State wii_state;
  while( true )
  {
    wii_state = wii.capture( );

    /* TODO
       if( wii_state.isButtonHomePushed( ) )
       std::cout << "Home ";
       if( wii_state.isButton1Pushed( ) )
       std::cout << "1 ";
       if( wii_state.isButton2Pushed( ) )
       std::cout << "2 ";
       if( wii_state.isButtonAPushed( ) )
       std::cout << "A ";
       if( wii_state.isButtonBPushed( ) )
       std::cout << "B ";
       if( wii_state.isButtonMinusPushed( ) )
       std::cout << "Minus ";
       if( wii_state.isButtonPlusPushed( ) )
       std::cout << "Plus ";
       if( wii_state.isButtonLeftPushed( ) )
       std::cout << "Left ";
       if( wii_state.isButtonRightPushed( ) )
       std::cout << "Right ";
       if( wii_state.isButtonDownPushed( ) )
       std::cout << "Down ";
       if( wii_state.isButtonUpPushed( ) )
       std::cout << "Up ";
       if( wii_state.isButtonZACCEL_BIT4Pushed( ) )
       std::cout << "BIT4 ";
       if( wii_state.isButtonZACCEL_BIT5Pushed( ) )
       std::cout << "BIT5 ";
       if( wii_state.isButtonZACCEL_BIT6Pushed( ) )
       std::cout << "BIT6 ";
       if( wii_state.isButtonZACCEL_BIT7Pushed( ) )
       std::cout << "BIT7 ";
       if( wii_state.isButtonUNKNOWNPushed( ) )
       std::cout << "UNKNOWN ";
       std::cout << std::endl;
    */

    /* TODO
      for( unsigned int i = 0; i < VRPN_WiiMote_State::NumberOfChannels; i++ )
      std::cout << wii_state.Channel[ i ] << " ";
      std::cout << std::endl;
    */

  } // elihw

  return( 0 );
}

// eof - $RCSfile$
