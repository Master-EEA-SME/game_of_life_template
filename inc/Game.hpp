#pragma once
#include <vector>
#include "Cell.hpp"
class Game
{
private:
    std::vector<std::vector<Cell>> _grid;
    size_t _width, _height;
    int _living_cells;
public:
    Game(int width, int height);
    ~Game();
    void begin();
    void iterate();
    void show();
    int get_number_of_living_cells();
};