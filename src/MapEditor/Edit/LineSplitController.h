#pragma once

#include "ModeController.h"

namespace slade::mapeditor
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
	bool onKeyBindRelease(string_view name) override;

private:
	MapEditContext *context_;
};
} // namespace slade::mapeditor
