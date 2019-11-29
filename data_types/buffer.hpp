//
// Created by Cameron Graybill on 11/25/19.
//

#ifndef ALIENDUDES_BUFFER_HPP
#define ALIENDUDES_BUFFER_HPP


#include <cstddef>
#include <array>

template <size_t width, size_t height>
class Buffer {
public:
    void clear(uint32_t color) {
        for (auto & row : data)
            row.fill(color);
    }

private:
    std::array<std::array<uint32_t, width>, height> data;
};


#endif //ALIENDUDES_BUFFER_HPP
