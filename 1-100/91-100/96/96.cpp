#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include <windows.h>
#include "96.h"
using namespace euler_96;

bool processGrid(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items, int loop, bool deep = true);

bool validateGrid(const std::vector<std::vector<int>>& grid)
{
    int rows, cols;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        rows = cols = 0;
        for (int j = 0; j < GRID_SIZE; j++)
        {
            rows += grid[i][j];
            cols += grid[j][i];
        }

        if (rows != 45 || cols != 45)
        {
            std::cout << "!!! FAILED VALIDATION ROWS & COLS !!!" << std::endl;
            return false;
        }
    }

    for (int i = 0; i < GRID_SIZE; i += 3)
    {
        for (int j = 0; j < GRID_SIZE; j += 3)
        {
            int sum = 0;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    sum += grid[k][l];
                }
            }

            if (sum != 45)
            {
                std::cout << "!!! FAILED VALIDATION SQUARE !!!" << std::endl;
                return false;
            }
        }
    }

    std::cout << "!!! SUCCEED VALIDATION !!!" << std::endl;
    return true;
}

bool validateGridUnique(const std::vector<std::vector<int>>& grid)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        std::vector<int> rows, cols;
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] != 0)
            {
                rows.push_back(grid[i][j]);
            }

            if (grid[j][i] != 0)
            {
                cols.push_back(grid[j][i]);
            }
        }

        std::sort(rows.begin(), rows.end());
        std::sort(cols.begin(), cols.end());

        auto lastRows = std::unique(rows.begin(), rows.end());
        auto lastCols = std::unique(cols.begin(), cols.end());

        if (lastRows != rows.end() || lastCols != cols.end())
        {
            return false;
        }
    
    }
    return true;
}

void showGrid(const std::vector<std::vector<int>>& grid)
{
    std::cout << std::endl;
    for (auto& row : grid)
    {
        for (auto& col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

bool predictGrid(const std::vector<std::vector<int>>& grid, const std::vector<std::vector<item>>& items, int loop, int size)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (items[i][j].cd.size() == size)
            {
                for (int k = 0; k < size; k++)
                {
                    auto copyGrid = grid;
                    auto copyItems = items;

                    copyItems[i][j].num = items[i][j].cd[k];
                    copyGrid[i][j] = items[i][j].cd[k];

                    //copyItems[i][j].cd.clear();
                    //copyItems[i][j].cd = { items[i][j].cd[k] };

                    auto it = std::remove(copyItems[i][j].cd.begin(), copyItems[i][j].cd.end(), copyGrid[i][j]);
                    copyItems[i][j].cd.erase(it, copyItems[i][j].cd.end());

                    if (processGrid(copyGrid, copyItems, loop + 1))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool processGrid(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items, int loop, bool deep)
{
    processGrid_Step_1(items);
    processGrid_Step_2(items);
    processGrid_Step_3(items);

    int total = 0;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (items[i][j].num == 0 && items[i][j].cd.size() == 0)
            {
                return false;
            }

            if (items[i][j].cd.size() == 1)
            {
                grid[i][j] = items[i][j].cd[0];
                items[i][j].num = items[i][j].cd[0];

                total++;
                items[i][j].cd.clear();
            }
        }
    }
    
    if (!validateGridUnique(grid))
    {
        std::cout << "<<< STRATEGY UNIQUE VALIDATION FAILED >>>" << std::endl;
        return false;
    }

    std::cout << "#Iteration - " << loop << "\t,\tTotal = " << total << std::endl;

    if (total != 0)
    {
        return processGrid(grid, items, ++loop);
    }

    if (validateGrid(grid) && validateGridUnique(grid))
    {
        return true;
    }

    int min = 9;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            //if (grid[i][j] == 0)
            if (items[i][j].num == 0)
            {
                int size = (int)items[i][j].cd.size();
                if (size == 0)
                {
                    return false;
                    //continue;
                }

                if (size < min && size != 0)
                {
                    min = size;
                }
            }
        }
    }

    std::cout << "---- PREDICTION via " << min << " ----" << std::endl;
    return predictGrid(grid, items, loop - 1, min);
    //return false;
}

int main()
{
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
    coninfo.dwSize.Y = 2000;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize);

    std::ifstream ifs("p096_sudoku.txt");
    if (!ifs.good())
    {
        return -1;
    }

    int id;
    std::vector<int> failed = { };
    for (id = 1; ifs.good(); id++)
    {
        std::string title = "Sudoku #" + std::to_string(id);
        SetConsoleTitle(title.c_str());

        auto grid = readGrid(ifs);
        auto items = buildItems(grid);

        if (std::find(failed.begin() , failed.end(), id) != failed.end())
        {
            continue;
        }

        std::cout << "--- Start Process Grid - #" << id << " ---" << std::endl;
        if (!processGrid(grid, items, 1))
        {
            failed.emplace_back(id);
        }
        
        std::cout << "-- Finish Process Grid - #" << id << " ---" << std::endl << std::endl;
        //system("pause");
    }

    std::cout << "|-------------------|" << std::endl;
    std::cout << "| Score = (" << id - 1 - failed.size() << " / " << id - 1 << ") |" << std::endl;
    std::cout << "|-------------------|" << std::endl;

    std::cout << std::endl << "#Failed = { ";
    for (auto f : failed)
    {
        std::cout << f << " ";
    }
    std::cout << "}" << std::endl << std::endl;
    
    return 0;
}
