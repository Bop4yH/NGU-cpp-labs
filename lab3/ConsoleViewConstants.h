#pragma once
#include <algorithm>



const int FIELD_CELL_WIDTH = 4;
const int FIELD_CELL_HEIGHT = 2;

const int FIELD_WIDTH = FIELD_CELL_WIDTH * 10 + 2;
const int FIELD_HEIGHT = FIELD_CELL_HEIGHT * 10 + 1;

const int GAMER1_FIELD_TOP_ANCHOR = 3;
const int GAMER1_FIELD_LEFT_ANCHOR = 2;


const std::string REMAINING_SHIPS_LABEL{ "remaining targets" };

const int REMAINING_SHIPS_WIDTH = REMAINING_SHIPS_LABEL.length() > FIELD_CELL_WIDTH * 4 ? REMAINING_SHIPS_LABEL.length() : FIELD_CELL_WIDTH * 4;
const int REMAINING_SHIPS_HEIGHT = FIELD_CELL_HEIGHT * 10 + 1 + 2 * 12;
const int REMAINING_SHIPS1_LEFT_ANCHOR = GAMER1_FIELD_LEFT_ANCHOR + FIELD_WIDTH + 1;
const int REMAINING_SHIPS_TOP_ANCHOR = GAMER1_FIELD_TOP_ANCHOR;


const int GAMER2_FIELD_TOP_ANCHOR = 3;
const int GAMER2_FIELD_LEFT_ANCHOR = REMAINING_SHIPS1_LEFT_ANCHOR + REMAINING_SHIPS_WIDTH + 1;

const int REMAINING_SHIPS2_LEFT_ANCHOR = GAMER2_FIELD_LEFT_ANCHOR + FIELD_WIDTH + 1;





const char UNCHECKED_CELL = (char)219;
const char DAMAGED_CELL = (char)176;
const char MISS_CELL = (char)255;

const std::string INFO_BAR_LAST_SHOT1_LABEL{ "gamer1 last shot" };
const std::string INFO_BAR_LAST_SHOT2_LABEL{ "gamer2 last shot" };

const int INFO_BAR_LAST_SHOT1_LEFT_ANCHOR = 1;
const int INFO_BAR_LAST_SHOT2_LEFT_ANCHOR = GAMER2_FIELD_LEFT_ANCHOR; //INFO_BAR_LAST_SHOT1_LEFT_ANCHOR + INFO_BAR_LAST_SHOT1_LABEL.length() + 5;

const int INFO_BAR_WIDTH = GAMER2_FIELD_LEFT_ANCHOR + INFO_BAR_LAST_SHOT2_LABEL.length(); //INFO_BAR_LAST_SHOT1_LABEL.length() + INFO_BAR_LAST_SHOT2_LABEL.length() + 10;
const int INFO_BAR_HEIGHT = 15;
const int INFO_BAR_TOP_ANCHOR = GAMER1_FIELD_TOP_ANCHOR + FIELD_HEIGHT + 3;
const int INFO_BAR_LEFT_ANCHOR = GAMER1_FIELD_LEFT_ANCHOR;

const int WINDOW_HEIGHT = REMAINING_SHIPS_TOP_ANCHOR + REMAINING_SHIPS_HEIGHT > INFO_BAR_TOP_ANCHOR + INFO_BAR_HEIGHT ?
REMAINING_SHIPS_TOP_ANCHOR + REMAINING_SHIPS_HEIGHT : INFO_BAR_TOP_ANCHOR + INFO_BAR_HEIGHT;// 30
const int WINDOW_WIDTH = REMAINING_SHIPS2_LEFT_ANCHOR + REMAINING_SHIPS_WIDTH > INFO_BAR_LEFT_ANCHOR + INFO_BAR_WIDTH ? REMAINING_SHIPS2_LEFT_ANCHOR + REMAINING_SHIPS_WIDTH + 5 : INFO_BAR_LEFT_ANCHOR + INFO_BAR_WIDTH + 5;   // 35