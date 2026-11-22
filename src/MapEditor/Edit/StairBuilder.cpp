
// -----------------------------------------------------------------------------
// SLADE - It's a Doom Editor
// Copyright(C) 2008 - 2026 Simon Judd
// Copyright(C) 2026 Ralf Gerlich
//
// Email:       sirjuddington@gmail.com
// Web:         http://slade.mancubus.net
// Filename:    StairBuilder.cpp
// Description: Map Editor stair builder implementation
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
#include "StairBuilder.h"
#include "Input.h"
#include "MapEditor/MapEditContext.h"

using namespace slade;
using namespace mapeditor;

// -----------------------------------------------------------------------------
//
// StairBuilder Class Functions
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Begins a stair
// -----------------------------------------------------------------------------
void StairBuilder::begin()
{
	log::debug("StairBuilder::begin()");
	context_->input().setMouseState(Input::MouseState::StairBuilding);
}

// -----------------------------------------------------------------------------
// Ends the stair building operation and applies changes if [accept] is true
// -----------------------------------------------------------------------------
void StairBuilder::end(bool accept)
{
	log::debug("StairBuilder::end(accept={})", accept);
}
