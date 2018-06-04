#include "../Includes/Map.h"
#include <iostream>
using namespace std;

int * Map::operator[](int idx)
{
	if (idx >= Vertical)
	{
		cout << "Map Index Error";
		return NULL;
	}
	return MapArray[idx];
}

[[deprecated]]
void Map::ShowMap()
{
	for (int i = 0; i < Vertical; i++)
	{
		for (int j = 0; j < Horizontal; j++)
		{
			cout << MapArray[i][j] << " ";
		}
		cout << endl;
	}
}