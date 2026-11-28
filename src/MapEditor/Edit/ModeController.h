#pragma once

#include "Input.h"

namespace slade::mapeditor
{
class ModeController
{
public:
	virtual bool mouseMove(int new_x, int new_y);
	virtual bool mouseDown(Input::MouseButton button, int x, int y, bool double_click = false);
	virtual bool mouseUp(Input::MouseButton button);
	virtual void onKeyBindPress(string_view name);
	virtual void onKeyBindRelease(string_view name);

private:
};
} // namespace slade::mapeditor
