#include "hwlib.hpp"

int main(void) {
  // kill the watchdog
<<<<<<< HEAD
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    for (;;){
        hwlib::cout << "this works via arduino";
        hwlib::wait_ms(1000);
    }
}