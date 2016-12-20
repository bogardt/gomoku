//
// Coordinates.cpp for Gomoku in /home/mikaz3/Tek3/B5/AI/Gomoku/tmp
// 
// Made by Thomas Billot
// Login   <mikaz3@epitech.net>
// 
// Started on  Tue Dec  6 19:08:55 2016 Thomas Billot
// Last update Thu Dec 15 17:22:53 2016 Thomas Billot
//

#include		"Map.hpp"

Map::Coordinates::Coordinates()
{}

Map::Coordinates::Coordinates(const unsigned int x,
			      const unsigned int y)
  : x(x),
    y(y)
{}

Map::Coordinates		Map::Coordinates::operator+(const Map::Coordinates &rhs) const
{
  return Coordinates(x + rhs.x, y + rhs.y);
}

Map::Coordinates	        Map::Coordinates::operator-(const Map::Coordinates &rhs) const
{
  return Coordinates(x - rhs.x, y - rhs.y);
}

bool				Map::Coordinates::operator==(const Map::Coordinates &rhs)
{
  return x == rhs.x && y == rhs.y;
}

bool				Map::Coordinates::operator!=(const Map::Coordinates &rhs)
{
  return x != rhs.x && y != rhs.y;
}
