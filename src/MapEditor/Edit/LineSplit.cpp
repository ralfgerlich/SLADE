
// -----------------------------------------------------------------------------
// SLADE - It's a Doom Editor
// Copyright(C) 2008 - 2026 Simon Judd
// Copyright(C) 2026 Ralf Gerlich
//
// Email:       sirjuddington@gmail.com
// Web:         http://slade.mancubus.net
// Filename:    LineSplit.cpp
// Description: Map Editor regular line splitting implementation
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110 - 1301, USA.
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
//
// Includes
//
// -----------------------------------------------------------------------------
#include "Main.h"
#include "LineSplit.h"
#include "Input.h"
#include "General/KeyBind.h"
#include "MapEditor/ItemSelection.h"
#include "MapEditor/MapEditContext.h"
#include "SLADEMap/MapObject/MapLine.h"
#include "SLADEMap/SLADEMap.h"

using namespace slade;
using namespace mapeditor;


// -----------------------------------------------------------------------------
//
// Variables
//
// -----------------------------------------------------------------------------
DCVAR(Int, linesplit_count, 1, CVar::Flag::Save, "Number of splits per line")


// -----------------------------------------------------------------------------
//
// LineSplit Class Functions
//
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Beging splitting a line
// -----------------------------------------------------------------------------
void LineSplit::begin()
{
	ItemSelection &selection = context_->selection();
	lines_ = selection.selectedLines();

	if (lines_.empty()) {
		// Nothing selected to process -> do not enter line split mode
		return;
	}

	// Calculate intermediate points for the first time
	calculate_intermediate_points();

	// Setup state
	context_->input().setMouseState(Input::MouseState::LineSplit);

	// Setup help text
	auto key_accept = KeyBind::bind("map_edit_accept").keysAsString();
	auto key_cancel = KeyBind::bind("map_edit_cancel").keysAsString();
	auto key_split_inc = KeyBind::bind("me2d_split_reg_inc").keysAsString();
	auto key_split_dec = KeyBind::bind("me2d_split_reg_dec").keysAsString();
	context_->setFeatureHelp(
		{ "Line Splitting",
			fmt::format("{} = Accept", key_accept),
			fmt::format("{} = Cancel", key_cancel),
			fmt::format("{} = Increase split count", key_split_inc),
			fmt::format("{} = Decrease split count", key_split_dec)
		});
}

// -----------------------------------------------------------------------------
// Ends the line splitting operation and applies changes if [accept] is true
// -----------------------------------------------------------------------------
void LineSplit::end(bool apply)
{
	if (!apply)
	{
		context_->setFeatureHelp({});
		return;
	}

	// Split the lines
	context_->beginUndoRecord("Split lines", true, true, false);
	for (unsigned line_idx = 0; line_idx < lines_.size(); line_idx++)
	{
		MapLine *line = lines_[line_idx];
		PointList split_points = intermediate_points_[line_idx];

		for (Vec2f point: split_points)
		{
			auto vertex = context_->map().createVertex(point);

			line = context_->map().splitLine(line, vertex);
		}
	}
	context_->endUndoRecord();

	// Clear feature help text
	context_->setFeatureHelp({});
}


// -----------------------------------------------------------------------------
// Changes the number of splits to add
// -----------------------------------------------------------------------------
void LineSplit::change_splits(int amount)
{
	log::debug("LineSplit::change_splits({})", amount);

	linesplit_count = wxMax(1, linesplit_count + amount);

	// Update intermediate points
	calculate_intermediate_points();
}

// -----------------------------------------------------------------------------
// Calculate all intermediate points
// -----------------------------------------------------------------------------
void LineSplit::calculate_intermediate_points()
{
	intermediate_points_.clear();

	for (MapLine* const line: lines_) {
		Vec2f start = line->start();
		const Vec2f end = line->end();
		const Vec2f sep = (end-start) / (float)(*linesplit_count+1);

		std::vector<Vec2f> points;
		for (unsigned point_idx = 0; point_idx < linesplit_count; point_idx++)
		{
			start += sep;
			points.push_back(start);
		}

		intermediate_points_.push_back(points);
	}
}
