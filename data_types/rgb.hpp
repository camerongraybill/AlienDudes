//
// Created by Cameron Graybill on 11/25/19.
//

#ifndef ALIENDUDES_RGB_HPP
#define ALIENDUDES_RGB_HPP

#include <cstdint>

class RGB {
public:
    RGB(uint8_t red, uint8_t green, uint8_t blue);

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    const uint8_t alpha{255};

    operator uint32_t() const;

};


#endif //ALIENDUDES_RGB_HPP
