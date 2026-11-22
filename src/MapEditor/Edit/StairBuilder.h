#pragma once

namespace slade::mapeditor
{
class MapEditContext;

class StairBuilder
{
public:
	explicit StairBuilder(MapEditContext &context): context_(&context) {}

	void begin();
	void end(bool apply = true);
private:
	MapEditContext *context_;
};

}; // namespace slade::mapeditor

