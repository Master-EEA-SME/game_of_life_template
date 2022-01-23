#include "Game.hpp"
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

Game::Game(int width, int height)
{
    _width = width;
    _height = height;
    _grid.reserve(_width);
    for (size_t i = 0; i < _height; i++)
    {
        _grid.push_back(std::vector<Cell>());
        _grid[i].reserve(_width);
        for (size_t j = 0; j < _width; j++)
        {
            _grid[i].push_back(Cell());
        }
    }   
}
Game::~Game()
{

}
void Game::begin()
{
    std::srand(std::time(NULL));
    for (auto &Row : _grid)
    {
        for (auto &cell : Row)
        {
            cell.set_status((std::rand() % 2) ? Cell::ALIVE : Cell::DEAD);
        }
    }
}
void Game::iterate()
{
    std::vector<std::vector<Cell>> next;
    // Allocate space for the next state
    next.reserve(_height);
    for (size_t i = 0; i < _height; i++)
        next.reserve(_width);
    next = _grid;
    int neighbours;
    // Apply the game rules
    for (size_t i = 0; i < _height; i++)
    {
        for (size_t j = 0; j < _width; j++)
        {
            neighbours = _grid[i][j].get_neighbours(_grid, j, i);
            // Calculer l'état de la cellule suivante ici
            next[i][j] = _grid[i][j]; // à modifier
        }
    }
    _grid = next;
}
void Game::show()
{
    move(0, 0);
    for (size_t i = 0; i < _height; i++)
    {
        for (size_t j = 0; j < _width; j++)
        {
            char c = _grid[i][j].is_alive() ? '#' : ' ';
            printw("%c", c);
        }
        printw("\n");
    }
}
int Game::get_number_of_living_cells()
{
    return 1;
}