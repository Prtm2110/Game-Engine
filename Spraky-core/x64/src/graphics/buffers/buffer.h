#pragma once

#include<GL/glew.h>

namespace sparky {
	namespace graphics {

		class Buffer {

		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componenetCount);
			void bind() const;
			void unbind() const;
			inline GLuint getComponentCount() const { return m_ComponentCount; }


		};
	}
}