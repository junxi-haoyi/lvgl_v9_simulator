#include <iostream>
#include "lv_porting.hpp"

LVGL Device;

int main(int, char**){
    std::cout << "Hello, from lvgl_simulator!\n";
    Device.init();
    Device.demo();
    Device.handler();

    
}
