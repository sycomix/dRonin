/**
******************************************************************************
*
* @file       sizelatlng.cpp
* @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
* @author     Tau Labs, http://taulabs.org, Copyright (C) 2013
* @brief      
* @see        The GNU Public License (GPL) Version 3
* @defgroup   TLMapWidget
* @{
* 
*****************************************************************************/
/* 
* This program is free software; you can redistribute it and/or modify 
* it under the terms of the GNU General Public License as published by 
* the Free Software Foundation; either version 3 of the License, or 
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful, but 
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
* for more details.
* 
* You should have received a copy of the GNU General Public License along 
* with this program; if not, see <http://www.gnu.org/licenses/>
*/
#include "sizelatlng.h"
#include "pointlatlng.h"
 
namespace internals {
SizeLatLng::SizeLatLng():heightLat(0),widthLng(0)
{

}
SizeLatLng::SizeLatLng(PointLatLng const&  pt)
{
  this->heightLat = pt.Lat();
  this->widthLng = pt.Lng();
}
SizeLatLng operator+(SizeLatLng const&  sz1, SizeLatLng const&  sz2)
{
    return SizeLatLng::Add(sz1, sz2);
}

SizeLatLng operator-(SizeLatLng const&  sz1, SizeLatLng const&  sz2)
{
  return SizeLatLng::Subtract(sz1, sz2);
}

bool operator==(SizeLatLng const&  sz1, SizeLatLng const&  sz2)
{
  return ((sz1.WidthLng() == sz2.WidthLng()) && (sz1.HeightLat() == sz2.HeightLat()));
}

bool operator!=(SizeLatLng const&  sz1, SizeLatLng const&  sz2)
{
  return !(sz1 == sz2);
}
SizeLatLng SizeLatLng::Empty=SizeLatLng();
}
