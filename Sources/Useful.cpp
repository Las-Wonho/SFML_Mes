/*************************************************************************
> File Name: Useful.cpp
> Project Name: 2048 in GSM
> Author: Wonho Ha aka Las
> Purpose: Some Usefull functions.
> Created Time: 2018/05/28
> Copyright (c) 2018, Wonho Ha aka Las
*************************************************************************/
#include"../Includes/Useful.h"
#include<iostream>
namespace Wonho_pp {	
	Screen_Move::Screen_Move() {
		
	};
	
	void Screen_Move::setMiddle(sf::Text& text) {
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
	};

	sf::RectangleShape Screen_Move::setTile(int x, int y, sf::Color color) {

		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(tile_x - round, tile_y - round));
		rectangle.setOutlineColor(sf::Color::Yellow);
		rectangle.setFillColor(sf::Color::Color(2, 65, 23, 100));
		rectangle.setOutlineThickness(round);
		auto[xx, yy] = PositionFunc(x, y);
		rectangle.setPosition(xx , yy);

		return rectangle;
	};

	void Screen_Move::setTextPosition(int x, int y, sf::Text & draw)
	{
		auto[tileX, tileY] = PositionFunc(x, y);
		tileX += tile_x / 2;
		tileY += tile_y / 2;
		setMiddle(draw);
		draw.setPosition(tileX, tileY);
		draw.setString("");
		setMiddle(draw);
	};

	

	void Screen_Move::setTileSize(int x, int y, int r = 1) {
		this->tile_x = x;
		this->tile_y = y;
		this->round = r;
	};

	void Screen_Move::setMapSize(int x, int y, int bolder) {
		this->map_x = x;
		this->map_y = y;
		this->yBolder = bolder;
	};

	void Screen_Move::setMapTile(std::vector<sf::RectangleShape>& vec)
	{
		for (int i = 0; i < MapSize; i++) {
			for (int j = 0; j < MapSize; j++) {
				vec.push_back(setTile(j, i, sf::Color::Green));
			}
		}
	};

	

	std::tuple<int, int> Screen_Move::PositionFunc(int x, int y) {
		x = (map_x / 2) + (MapSize % 2)*(-(tile_x / 2)) - (MapSize / 2 * tile_x) + (x * tile_x);
		y = (map_y / 2) + (MapSize % 2)*(-(tile_y / 2)) - (2 * tile_y) + (y * tile_y) + yBolder;
		return { x, y };
	};
};
