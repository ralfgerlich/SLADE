#pragma once

#include "ModeView.h"

namespace slade
{

	namespace mapeditor {
		class MapEditContext;
	} // namespace mapeditor
namespace gl
{
	namespace draw2d
	{
		struct Context;

		class LineSplitView: public ModeView
		{
		public:
			LineSplitView(mapeditor::MapEditContext &context);
			void draw(Context& dc) const override;
		private:
			slade::mapeditor::MapEditContext *context_;
		};
	} // namespace draw2d
} // namespace gl
} // namespace slade
