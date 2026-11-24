#pragma once

namespace slade::mapeditor
{
class MapEditContext;

class LineSplit
{
public:
	typedef std::vector<Vec2f> PointList;

	explicit LineSplit(MapEditContext& context) : context_(&context) {}

	void begin();
	void end(bool apply = true);

	void change_splits(int amount);

	const std::vector<PointList>& intermediate_points() const { return intermediate_points_; }
private:
	MapEditContext* 		context_;

	// lines to process
	std::vector<MapLine*>	lines_;

	// The list of intermediate points per line
	std::vector<PointList>	intermediate_points_;

	void calculate_intermediate_points();
};
} // namespace slade::mapeditor
