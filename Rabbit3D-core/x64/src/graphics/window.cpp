#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

namespace rabbit {
    namespace graphics {

        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        void windowResize(GLFWwindow* window, int width, int height);

        Window::Window(const char* title, int width, int height) {
            m_Title = title;
            m_Width = width;
            m_Height = height;
            m_Closed = false;
            if (!init())
                glfwTerminate();

         
        }

        Window::~Window() {
            glfwDestroyWindow(m_Window);
            glfwTerminate();
        }

        bool Window::init() {
            if (!glfwInit()) {
                std::cout << "Failed to initialize GLFW" << std::endl;
                return false;
            }

            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
            if (!m_Window) {
                glfwTerminate();
                std::cout << "Failed to create GLFW window!" << std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_Window);
            glfwSetWindowUserPointer(m_Window, this);
            glfwSetWindowSizeCallback(m_Window, windowResize);
            glfwSetKeyCallback(m_Window, key_callback);
            glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
            glfwSetCursorPosCallback(m_Window, cursor_position_callback);

            if (glewInit() != GLEW_OK) {
                std::cout << "Could not initialize GLEW!" << std::endl;
            }

            std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
            return true;
        }

        bool Window::isKeyPressed(unsigned int keycode) const{
            if (keycode >= MAX_KEYS)
                return false;
            return m_Keys[keycode];
        }

        bool Window::isMouseButtonPressed(unsigned int button) const{
            if (button >= MAX_BUTTONS)
                return false;
            return m_MouseButtons[button];
        }

        void Window::getMousePosition(double& x, double& y) const{
            x = mx;
            y = my;
        }

        void Window::update() {
			GLenum err = glGetError();
			if (err != GL_NO_ERROR) {
				std::cerr << "OpenGL Error: " << err << std::endl;
			}

            glfwPollEvents();
            glfwSwapBuffers(m_Window);
        }

        void Window::clear() const {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        bool Window::closed() const {
            return glfwWindowShouldClose(m_Window) == 1;
        }

        void windowResize(GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (key < 0 || key >= MAX_KEYS) {
                std::cerr << "Key " << key << " is out of bounds!" << std::endl;
                return;
            }
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->m_Keys[key] = action != GLFW_RELEASE;
        }

        void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
            if (button < 0 || button >= MAX_BUTTONS) {
                std::cerr << "Mouse button " << button << " is out of bounds!" << std::endl;
                return;
            }
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->m_MouseButtons[button] = action != GLFW_RELEASE;
        }

        void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->mx = xpos;
            win->my = ypos;
        }
    }
}
