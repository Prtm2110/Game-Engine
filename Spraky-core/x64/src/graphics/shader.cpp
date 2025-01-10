#include "shader.h"
#include <iostream>

using namespace sparky;
using namespace graphics;
using namespace utils;

namespace sparky {
	namespace graphics {

		Shader::Shader(const char* vertPath, const char* fragPath)
			: m_VertPath(vertPath), m_FragPath(fragPath) // Updated variable names
		{
			m_ShaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}

        GLuint Shader::load()
        {
        GLuint program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertSourceStr = read_file(m_VertPath);
        const char* vertSource = vertSourceStr.c_str();
           
        std::string fragSourceStr = read_file(m_FragPath);
            const char* fragSource = fragSourceStr.c_str();

        // Vertex Shader
        glShaderSource(vertex, 1, &vertSource, NULL);
        glCompileShader(vertex);

        GLint result;
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
        GLint length;
        glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(vertex, length, &length, &error[0]);
        std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
        glDeleteShader(vertex);
        return 0;
        }

        // Fragment Shader
        glShaderSource(fragment, 1, &fragSource, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
        GLint length;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(fragment, length, &length, &error[0]);
        std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
        glDeleteShader(fragment);
        return 0;
        }

        // Attach shaders to program
        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;
        }

		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}

	}
}
