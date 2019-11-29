#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string_view>
#include "data_types/buffer.hpp"
#include "data_types/window.hpp"
#include "data_types/rgb.hpp"
#include "gl_helpers.hpp"

constexpr std::string_view vertex_shader =
        "\n"
        "#version 330\n"
        "\n"
        "noperspective out vec2 TexCoord;\n"
        "\n"
        "void main(void){\n"
        "\n"
        "    TexCoord.x = (gl_VertexID == 2)? 2.0: 0.0;\n"
        "    TexCoord.y = (gl_VertexID == 1)? 2.0: 0.0;\n"
        "    \n"
        "    gl_Position = vec4(2.0 * TexCoord - 1.0, 0.0, 1.0);\n"
        "}\n";

constexpr std::string_view fragment_shader =
        "\n"
        "#version 330\n"
        "\n"
        "uniform sampler2D buffer;\n"
        "noperspective in vec2 TexCoord;\n"
        "\n"
        "out vec3 outColor;\n"
        "\n"
        "void main(void){\n"
        "    outColor = texture(buffer, TexCoord).rgb;\n"
        "}\n";



int main() {
    setup_glfw();
    Window<640, 480> w{"Space Invaders"};
    RGB clear_color{0, 128, 0};
    Buffer<128, 128> b{};
    b.clear(clear_color);

    glfwMakeContextCurrent(w.raw_window);
    glew_init();
    glClearColor(1.0, 0.0, 0.0, 1.0);
    while (!glfwWindowShouldClose(w))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(w);

        glfwPollEvents();
    }
    glfwTerminate();
}
