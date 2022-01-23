#include "Cell.hpp"

Cell::Cell()
{
    
}
Cell::~Cell()
{

}
void Cell::set_status(status_t status)
{

}
bool Cell::is_alive() const
{
    return true;
}
int Cell::get_neighbours(const std::vector<std::vector<Cell>> &grid, size_t x, size_t y) const
{
    int neighbours = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            // Check if we are in bounds
            if (((y + i) >= 0 && (y + i) < grid.size() && (x + j) >= 0 && (x + j) < grid[0].size()))
                // Check if we are not ourself
                if (!(i == 0 && j == 0))
                    if (grid[y + i][x + j].is_alive())
                        neighbours++;
        }
    }
    return neighbours;
}