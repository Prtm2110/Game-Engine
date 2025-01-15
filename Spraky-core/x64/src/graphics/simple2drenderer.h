#pragma once
#include "renderable2d.h"
#include <deque>

namespace sparky {
	namespace graphics {
		class Simple2DRenderer
		{
		public:
			std::deque<const Renderable2D*> m_RenderQueue;
			Simple2DRenderer() {}
		public:
			virtual void submit(const Renderable2D* renderable);
			virtual void flush();
		};
	}
}
