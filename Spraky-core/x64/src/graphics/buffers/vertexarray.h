#pragma once
#include <GL/glew.h>
#include <vector>
#include "buffer.h"

 namespace sparky{
	 namespace graphics {
		 class VertexArray {
		 private:
			 GLuint m_ArrayID;
			 std::vector<Buffer*> m_Buffers;
		 public:
			 VertexArray();
			 ~VertexArray();
			 void addBuffer(Buffer* buffer, GLuint index);
			 void bind() const;
			 void unbind() const;
		 };
	 }
}