//
// Created by Cameron Graybill on 11/25/19.
//

#include "rgb.hpp"

RGB::operator uint32_t() const {
    uint32_t red_shift(red << 24u);
    uint32_t green_shift(green << 24u);
    uint32_t blue_shift(blue << 24u);

    return red_shift | green_shift | blue_shift | alpha;
}

RGB::RGB(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}

