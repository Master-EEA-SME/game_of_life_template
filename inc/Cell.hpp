#pragma once
#include <vector>
class Cell
{
public:
    enum status_t {ALIVE, DEAD};
private:
    status_t _status;
public:
    Cell();
    ~Cell();
    void set_status(status_t status);
    bool is_alive() const;
    int get_neighbours(const std::vector<std::vector<Cell>> &grid, size_t x, size_t y) const;
};