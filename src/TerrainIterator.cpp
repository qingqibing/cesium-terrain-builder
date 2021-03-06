#include "TerrainIterator.hpp"

/*******************************************************************************
 * Copyright 2014 GeoData <geodata@soton.ac.uk>
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *******************************************************************************/

/**
 * @file TerrainIterator.cpp
 * @brief This defines the `TerrainIterator` class
 */

using namespace ctb;

ctb::TerrainIterator::TerrainIterator(const TerrainTiler &tiler):
  TilerIterator(tiler)
{}

ctb::TerrainIterator::TerrainIterator(const TerrainTiler &tiler, i_zoom startZoom, i_zoom endZoom):
  TilerIterator(tiler, startZoom, endZoom)
{}

/**
 * @details use the tiler to create a `TerrainTile` on the fly for the
 * `TileCoordinate` currently pointed to by the iterator.
 */
TerrainTile
ctb::TerrainIterator::operator*() const {
  return tiler.createTerrainTile(currentTile);
}
