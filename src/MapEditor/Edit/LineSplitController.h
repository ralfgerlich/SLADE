#pragma once

#include "ModeController.h"

namespace slade
{
namespace gl::draw2d {
	class LineSplitView;
} // namespace gl::draw2d

namespace mapeditor
{
class MapEditContext;
class LineSplit;

class LineSplitController: public ModeController
{
public:
	explicit LineSplitController(MapEditContext &context);

	void begin();
	void apply();
	void cancel();

	bool onKeyBindPress(string_view name) override;
private:
	MapEditContext *context_;

	std::unique_ptr<gl::draw2d::LineSplitView> view_;
};
} // namespace slade::mapeditor
} // namespace slade
