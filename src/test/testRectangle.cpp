#include "rectangle.hh"

#define BOOST_TEST_MODULE RectangleTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(rectangle_test)
{
  Rectangle r0(2, 5);

  BOOST_CHECK( r0.Area() == 10 );        // #1 continues on error

  BOOST_REQUIRE( r0.Area() == 10 );      // #2 throws on error

  // if( add( 2,2 ) != 4 )
  //   BOOST_ERROR( "Ouch..." );            // #3 continues on error

  // if( add( 2,2 ) != 4 )
  //   BOOST_FAIL( "Ouch..." );             // #4 throws on error

  // if( add( 2,2 ) != 4 ) throw "Ouch..."; // #5 throws on error

  // BOOST_CHECK_MESSAGE( add( 2,2 ) == 4,  // #6 continues on error
  //                         "add(..) result: " << add( 2,2 ) );

  // BOOST_CHECK_EQUAL( add( 2,2 ), 4 );	  // #7 continues on error
}
