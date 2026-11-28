
// -----------------------------------------------------------------------------
// SLADE - It's a Doom Editor
// Copyright(C) 2008 - 2026 Simon Judd
// Copyright(C) 2026 Ralf Gerlich
//
// Email:       sirjuddington@gmail.com
// Web:         http://slade.mancubus.net
// Filename:    LineSplitView.cpp
// Description: LineSplitView class - Handle drawing in line split mode
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
#include "LineSplitView.h"
#include "General/ColourConfiguration.h"
#include "General/CVar.h"
#include "MapEditor/MapEditContext.h"
#include "MapEditor/Edit/LineSplit.h"
#include "MapEditor/Renderer/Renderer.h"
#include "OpenGL/Draw2D.h"
#include "OpenGL/OpenGL.h"
#include "OpenGL/View.h"

using namespace slade;
using namespace mapeditor;
using namespace gl;
using namespace draw2d;

EXTERN_CVAR(Bool,map2d_vertex_round)
EXTERN_CVAR(Int,map2d_vertex_size)

// -----------------------------------------------------------------------------
//
// LineSplitView Class Functions
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// LineSplitView Constructor
// -----------------------------------------------------------------------------
LineSplitView::LineSplitView(MapEditContext &context):
	context_(&context)
{
}

// -----------------------------------------------------------------------------
// Draw the line split points
// -----------------------------------------------------------------------------
void LineSplitView::draw(Context& dc) const
{
	LineSplit& line_split = context_->lineSplit();

	auto &intermediate_points = line_split.intermediate_points();

	for (auto &points: intermediate_points)
	{
		dc.setColourFromConfig(colourconfig::MapEditor::LineSplit);

		// Draw points
		auto          ps_type = map2d_vertex_round ? PointSpriteType::Circle : PointSpriteType::Textured;
		dc.pointsprite_type   = ps_type;
		dc.pointsprite_radius = map2d_vertex_size / context_->renderer().view().scale(true).x;
		dc.drawPointSprites(points);
	}
}
