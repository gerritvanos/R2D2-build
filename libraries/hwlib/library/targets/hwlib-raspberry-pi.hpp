#// ==========================================================================
//
// File      : hwlib-uno.hpp
// Part of   : C++ hwlib library for close-to-the-hardware OO programming
// Copyright : wouter@voti.nl 2017-2019
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

// this file contains Doxygen lines
/// @file

#ifndef HWLIB_RPI3_H
#define HWLIB_RPI3_H

#define _HWLIB_TARGET_WAIT_US_BUSY
#include HWLIB_INCLUDE( ../hwlib-all.hpp )

#include <stdint.h>

#include <wiringPi.h>

namespace rpi3 {

/// raspbery pi 3 pin names
///
/// These are the pins of an Arduino Uno board.
enum class pins {
   d3, d5, d7, d8, d10, d11, d12, d13, d15, d16, 
   d18, d19, d21, d22, d23, d24, d26, d27, d28, 
   d29, d31, d32, d33, d35, d36, d37, d38, d40,
/// \cond INTERNAL    
   SIZE_THIS_IS_NOT_A_PIN
/// \endcond   
};
   
/// \cond INTERNAL 

struct pin_info_type { 
   uint8_t wiring_pi; 
   uint8_t rpi_bcm; 
};

const pin_info_type pin_info_array[ (int) pins::SIZE_THIS_IS_NOT_A_PIN ] = {
   { 8, 2 },  // d3
   { 9, 3 },  // d5
   { 7, 4 },  // d7
   { 15, 14 },  // d8
   { 16, 15 },  // d10
   { 0, 17 },  // d11
   { 1, 18 },  // d12
   { 2, 27 },  // d13
   { 3, 22 },  // d15
   { 4, 23 },  // d16
   { 5, 24 },  // d18
   { 12, 10 },  // d19
   { 13, 9 },  // d21
   { 6, 25 },  // d22
   { 14, 11 },  // d23
   { 10, 8 },  // d24
   { 11, 7 },  // d26
   { 30, 0 },  // d27
   { 31, 1 },  // d28
   { 21, 5 },  // d29
   { 22, 6 },  // d31
   { 26, 12 },  // d32
   { 23, 13 },  // d33
   { 24, 19 },  // d35
   { 27, 16 },  // d36
   { 25, 26 },  // d37   
   { 28, 20 },  // d38
   { 29, 21 },  // d40
};

const pin_info_type & HWLIB_WEAK pin_info( pins name ){
   uint_fast8_t n = static_cast< uint_fast8_t>( name );
   if( n >= static_cast< uint_fast8_t>( pins::SIZE_THIS_IS_NOT_A_PIN )){
      HWLIB_PANIC_WITH_LOCATION;
   }
   return pin_info_array[ n ];
}
   
/// pin_in implementation for an RPI
class pin_in : public hwlib::pin_in {
private:
   uint8_t wiring_pi;
   uint8_t rpi_bcm;
 
public:
   pin_in( uint8_t wiring_pi, uint8_t rpi_bcm ): 
      wiring_pi(wiring_pi), 
      rpi_bcm(rpi_bcm)
   {
       pinMode(wiring_pi, INPUT);
   }
   
   pin_in( pins name ): 
      pin_in{ 
         pin_info( name ).wiring_pi,
         pin_info( name ).rpi_bcm 
      }
   {}
   
   bool read() override {
      return digitalRead(wiring_pi);
   }
   
   void refresh() override {}
   
};

/// pin_out implementation for a ATMega328P
class pin_out : public hwlib::pin_out {
private:
   uint8_t wiring_pi;
   uint8_t rpi_bcm;
   
public:

   /// Arduino Uno pin_out constructor from ATMega328P port/pin numbers
   ///
   /// This call creates a pin_out from an ATMega328P port/pin
   /// number pair.
   ///
   /// This constructor sets the pin direction to output.
   pin_out( uint8_t wiring_pi, uint8_t rpi_bcm ): 
      wiring_pi(wiring_pi), 
      rpi_bcm(rpi_bcm)
   {
       pinMode(wiring_pi, OUTPUT);
   }
   
   /// Arduino Uno pin_out constructor from an Uno pin name
   ///
   /// This call creates a pin_out from an Arduino Uno pin name.
   ///
   /// This constructor sets the pin direction to output.
   pin_out( pins name ): 
      pin_out{ 
         pin_info( name ).wiring_pi,
         pin_info( name ).rpi_bcm 
      }
   {}
   
   void write( bool v ) override {
       digitalWrite(wiring_pi, v);
   }

   void flush() override {}

};

}; // namespace rpi3

namespace hwlib {

namespace target = ::rpi3;
   
#ifdef _HWLIB_ONCE

void HWLIB_WEAK wait_us_asm( int n ){ 
    // TODO add wait
}

void HWLIB_WEAK wait_us_busy( int_fast32_t n ){ 
    // TODO add wait
} 

void HWLIB_WEAK uart_putc( char c ){
    // TODO add serial
}

char HWLIB_WEAK uart_getc(){
    // TODO add serial
}


#endif

}; //namespace hwlib   

#endif // RPI_HPP
