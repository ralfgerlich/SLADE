
// -----------------------------------------------------------------------------
// SLADE - It's a Doom Editor
// Copyright(C) 2008 - 2026 Simon Judd
// Copyright(C) 2026 Ralf Gerlich
//
// Email:       sirjuddington@gmail.com
// Web:         http://slade.mancubus.net
// Filename:    LineSplitController.cpp
// Description: Map Editor mode controller for line split mode
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
#include "Input.h"
#include "General/KeyBind.h"
#include "LineSplitController.h"
#include "LineSplit.h"
#include "MapEditor/ItemSelection.h"
#include "MapEditor/MapEditContext.h"
#include "MapEditor/Renderer/Renderer.h"
#include "MapEditor/Renderer/2D/LineSplitView.h"

using namespace slade;
using namespace mapeditor;


// -----------------------------------------------------------------------------
//
// LineSplitController Class Functions
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// LineSplitController constructor
// -----------------------------------------------------------------------------
LineSplitController::LineSplitController(MapEditContext &context):
	context_(&context),
	view_(std::make_unique<gl::draw2d::LineSplitView>(context))
{
}

// -----------------------------------------------------------------------------
// Begin operation
// -----------------------------------------------------------------------------
void LineSplitController::begin()
{
	ItemSelection &selection = context_->selection();
	std::vector<MapLine*> lines = selection.selectedLines();

	if (lines.empty()) {
		// Nothing selected to process -> do not enter line split mode
		return;
	}
	context_->lineSplit().begin(lines);

	// Setup state
	context_->input().setMouseModeDelegate(this);
	context_->renderer().setModeView(view_.get());

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
// Apply the splits
// -----------------------------------------------------------------------------
void LineSplitController::apply()
{
	context_->beginUndoRecord("Split lines", true, true, false);
	context_->lineSplit().apply_splits();
	context_->endUndoRecord();

	context_->renderer().clearModeView();

	// Clear feature help text
	context_->setFeatureHelp({});

}

// -----------------------------------------------------------------------------
// Cancel operation
// -----------------------------------------------------------------------------
void LineSplitController::cancel()
{
	context_->lineSplit().cancel();

	context_->renderer().clearModeView();

	// Clear feature help text
	context_->setFeatureHelp({});
}

// -----------------------------------------------------------------------------
// Handle key press
// -----------------------------------------------------------------------------
bool LineSplitController::onKeyBindPress(string_view name)
{
	// Accept line draw
	if (name == "map_edit_accept")
	{
		context_->input().setMouseState(Input::MouseState::Normal);
		apply();
	}

	// Cancel line draw
	else if (name == "map_edit_cancel")
	{
		context_->input().setMouseState(Input::MouseState::Normal);
		cancel();
	}

	// Increase line split count
	else if (name == "me2d_split_reg_inc")
	{
		context_->lineSplit().change_splits(1);
	}

	// Decrease line split count
	else if (name == "me2d_split_reg_dec")
	{
		context_->lineSplit().change_splits(-1);
	}

	return ModeController::onKeyBindPress(name);
}
