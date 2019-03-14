
#include <hwlib.hpp>

int main(void) {
    hwlib::cout << "Raspberry Pi blink\n";

    hwlib::target::init();

    auto led = hwlib::target::pin_out(hwlib::target::pins::d3);

    while (true) {
        led.write(true); // on
        hwlib::wait_ms(500);
        led.write(false); // on
        hwlib::wait_ms(500);
    }

    return 0;
}
