
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
#include "LineSplitController.h"
#include "LineSplit.h"
#include "MapEditor/MapEditContext.h"

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
	context_(&context)
{
}

// -----------------------------------------------------------------------------
// Begin operation
// -----------------------------------------------------------------------------
void LineSplitController::begin()
{
	context_->lineSplit().begin();
}

// -----------------------------------------------------------------------------
// Apply operation
// -----------------------------------------------------------------------------
void LineSplitController::apply()
{
	context_->lineSplit().end();
}

// -----------------------------------------------------------------------------
// Cancel operation
// -----------------------------------------------------------------------------
void LineSplitController::cancel()
{
	context_->lineSplit().end(false);
}

// -----------------------------------------------------------------------------
// Handle key press
// -----------------------------------------------------------------------------
bool LineSplitController::onKeyBindPress(string_view name)
{
	return ModeController::onKeyBindPress(name);
}

// -----------------------------------------------------------------------------
// Handle key release
// -----------------------------------------------------------------------------
bool LineSplitController::onKeyBindRelease(string_view name)
{
	return ModeController::onKeyBindRelease(name);
}
