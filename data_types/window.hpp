//
// Created by Cameron Graybill on 11/25/19.
//

#ifndef ALIENDUDES_WINDOW_HPP
#define ALIENDUDES_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string_view>

template <int height, int width>
class Window {
public:
    explicit Window(std::string_view name): raw_window(glfwCreateWindow(width, height, name.cbegin(), NULL, NULL)) {
        if (!raw_window) {
            glfwTerminate();
            throw std::exception();
        }
    }

    operator GLFWwindow * () const {
        return raw_window;
    }

    GLFWwindow * const raw_window;

    virtual ~Window() {
        glfwDestroyWindow(raw_window);
    }

};


#endif //ALIENDUDES_WINDOW_HPP
