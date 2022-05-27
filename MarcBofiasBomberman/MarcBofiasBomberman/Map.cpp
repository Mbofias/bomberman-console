#include "pch.h"
#include "Map.h"
#include <iostream>

Map::Map()
{
}
Map::~Map()
{
}
char Map::GetMap(int y, int x)
{
	return map[y][x];
}
void Map::SetPosition(char sprite, Vector2D location)
{
	map[location.y][location.x] = sprite;
}
void Map::Reset()
{
	for (int w = 0; w < width; w++)
		map[0][w] = 'X';
	for (int w = 0; w < width; w++)
		map[12][w] = 'X';
	for (int h = 0; h < height; h++)
		map[h][0] = 'X';
	for (int h = 0; h < height; h++)
		map[h][12] = 'X';

	for (int h = 1; h < height - 1; h++)
		for (int w = 1; w < width - 1; w++)
			map[h][w] = ' ';

	for (int h = 2; h < height - 2; h += 2)
			for (int w = 2; w < width; w += 2)
				map[h][w] = 'X';
}
void Map::Draw(Console consola)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			consola.PutChar(x, y, map[x][y]);
		}
	}
}
bool Map::LokingFor(char sprite)
{
	for (int h = 2; h < height; h++)
		for (int w = 1; w < width; w++)
			if (map[h][w] == sprite)
				return true;
	return false;
}