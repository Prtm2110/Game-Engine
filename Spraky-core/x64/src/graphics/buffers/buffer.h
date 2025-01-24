#pragma once

#include<GL/glew.h>

namespace rabbit {
	namespace graphics {

		class Buffer {

		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componenetCount);
			~Buffer();
			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return m_ComponentCount; }


		};
	}
}