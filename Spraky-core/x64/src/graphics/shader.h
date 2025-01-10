#pragma once

#include <vector>
#include <GL/glew.h>
#include "../utils/fileutils.h"

namespace sparky {
	namespace graphics {
		
		class Shader {
		private:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath; // Updated variable names
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();
			void enable() const;
			void disable() const;
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	
	}
}