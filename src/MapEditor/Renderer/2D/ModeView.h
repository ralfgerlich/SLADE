#pragma once

namespace slade
{

namespace gl
{
	namespace draw2d
	{
		struct Context;

		class ModeView
		{
		public:
			virtual void draw(gl::draw2d::Context& dc) const = 0;
		};
	} // namespace draw2d
} // namespace gl
} // namespace slade
