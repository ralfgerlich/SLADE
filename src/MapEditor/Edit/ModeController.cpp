
// -----------------------------------------------------------------------------
// SLADE - It's a Doom Editor
// Copyright(C) 2008 - 2026 Simon Judd
// Copyright(C) 2026 Ralf Gerlich
//
// Email:       sirjuddington@gmail.com
// Web:         http://slade.mancubus.net
// Filename:    LineSplit.cpp
// Description: Map Editor mode controller abstract base class
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
#include "ModeController.h"
#include "Input.h"

using namespace slade;
using namespace mapeditor;


// -----------------------------------------------------------------------------
//
// ModeController Class Functions
//
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Handle mouse movement
// -----------------------------------------------------------------------------
bool ModeController::mouseMove(int new_x, int new_y)
{
	return false;
}

// -----------------------------------------------------------------------------
// Handle mouse button press (left/right only, rest is handled by key bindings)
// -----------------------------------------------------------------------------
bool ModeController::mouseDown(Input::MouseButton button, int x, int y, bool double_click)
{
	return false;
}

// -----------------------------------------------------------------------------
// Handle mouse button release (left/right only, rest is handled by key bindings)
// -----------------------------------------------------------------------------
bool ModeController::mouseUp(Input::MouseButton button)
{
	return false;
}

// -----------------------------------------------------------------------------
// Handle key press
// -----------------------------------------------------------------------------
void ModeController::onKeyBindPress(string_view name)
{
}

// -----------------------------------------------------------------------------
// Handle key release
// -----------------------------------------------------------------------------
void ModeController::onKeyBindRelease(string_view name)
{
}
