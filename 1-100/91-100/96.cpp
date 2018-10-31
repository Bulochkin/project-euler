#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include <windows.h>
#define GRID_SIZE 9

////////////////////////////////////////////////////////////////////////////////

struct item
{
    int x, y, num = 0;
    std::vector<int> cd = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
};

std::vector<std::vector<int>> readGrid(std::ifstream& ifs)
{
    std::string nums;
    std::getline(ifs, nums, '\n');

    std::vector<std::vector<int>> grid;
    while (ifs.good() && grid.size() != GRID_SIZE)
    {
        std::vector<int> toPush;
        std::getline(ifs, nums, '\n');

        for (auto num : nums)
        {
            toPush.push_back(num - 48);
        }

        grid.emplace_back(std::move(toPush));
    }

    return grid;
}

std::vector<std::vector<item>> buildItems(const std::vector<std::vector<int>>& grid)
{
    std::vector<std::vector<item>> items(GRID_SIZE, std::vector<item>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            items[i][j].x = i;
            items[i][j].y = j;

            if (grid[i][j] != 0)
            {
                items[i][j].num = grid[i][j];
                items[i][j].cd.clear();
            }
        }
    }
    return items;
}

////////////////////////////////////////////////////////////////////////////////

void processGrid_Strategy_1(std::vector<std::vector<item>>& items)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (items[i][j].num != 0)
            {
                continue;
            }

            for (int r = 0; r < GRID_SIZE; r++)
            {
                if (items[i][r].num != 0)
                {
                    auto it = std::remove(items[i][j].cd.begin(), items[i][j].cd.end(), items[i][r].num);
                    items[i][j].cd.erase(it, items[i][j].cd.end());
                }
            }

            for (int c = 0; c < GRID_SIZE; c++)
            {
                if (items[c][j].num != 0)
                {
                    auto it = std::remove(items[i][j].cd.begin(), items[i][j].cd.end(), items[c][j].num);
                    items[i][j].cd.erase(it, items[i][j].cd.end());
                }
            }

            for (int is = 3 * (i / 3); is < 3 * (i / 3) + 3; is++)
            {
                for (int js = 3 * (j / 3); js < 3 * (j / 3) + 3; js++)
                {
                    if (items[is][js].num != 0)
                    {
                        auto it = std::remove(items[i][j].cd.begin(), items[i][j].cd.end(), items[is][js].num);
                        items[i][j].cd.erase(it, items[i][j].cd.end());
                    }
                }
            }
        }
    }
}

void processGrid_Strategy_2(std::vector<std::vector<item>>& items)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (items[i][j].num != 0)
            {
                continue;
            }

            std::vector<int> indexes;
            const auto& toSearch = items[i][j].cd;

            for (int k = 0; k < GRID_SIZE; k++)
            {
                if (items[i][k].num == 0 && toSearch == items[i][k].cd)
                {
                    indexes.emplace_back(k);
                }
            }

            if (indexes.size() > 1 && indexes.size() == toSearch.size())
            {
                for (int k = 0; k < GRID_SIZE; k++)
                {
                    auto pos = std::find(indexes.begin(), indexes.end(), k);
                    if (pos == indexes.end())
                    {
                        for (auto to : toSearch)
                        {
                            auto it = std::remove(items[i][k].cd.begin(), items[i][k].cd.end(), to);
                            items[i][k].cd.erase(it, items[i][k].cd.end());
                        }
                    }
                }
            }

            indexes.clear();
            for (int k = 0; k < GRID_SIZE; k++)
            {
                if (items[k][j].num == 0 && toSearch == items[k][j].cd)
                {
                    indexes.emplace_back(k);
                }
            }

            if (indexes.size() > 1 && indexes.size() == toSearch.size())
            {
                for (int k = 0; k < GRID_SIZE; k++)
                {
                    auto pos = std::find(indexes.begin(), indexes.end(), k);
                    if (pos == indexes.end())
                    {
                        for (auto to : toSearch)
                        {
                            auto it = std::remove(items[k][j].cd.begin(), items[k][j].cd.end(), to);
                            items[k][j].cd.erase(it, items[k][j].cd.end());
                        }
                    }
                }
            }

            std::vector<std::pair<int, int>> indexes2;
            for (int is = 3 * (i / 3); is < 3 * (i / 3) + 3; is++)
            {
                for (int js = 3 * (j / 3); js < 3 * (j / 3) + 3; js++)
                {
                    if (items[is][js].num == 0 && toSearch == items[is][js].cd)
                    {
                        indexes2.emplace_back(std::make_pair(is, js));
                    }
                }
            }

            if (indexes2.size() > 1 && indexes2.size() == toSearch.size())
            {
                for (int is = 3 * (i / 3); is < 3 * (i / 3) + 3; is++)
                {
                    for (int js = 3 * (j / 3); js < 3 * (j / 3) + 3; js++)
                    {
                        auto pos = std::find(indexes2.begin(), indexes2.end(), std::make_pair(is, js));
                        if (pos == indexes2.end())
                        {
                            for (auto to : toSearch)
                            {
                                auto it = std::remove(items[is][js].cd.begin(), items[is][js].cd.end(), to);
                                items[is][js].cd.erase(it, items[is][js].cd.end());
                            }
                        }
                    }
                }
            }
        }
    }
}

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

bool processGrid(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items, int loop);

bool predictGrid(std::vector<std::vector<int>>& grid, const std::vector<std::vector<item>>& items, int loop, int size)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (items[i][j].cd.size() == size)
            {
                auto copyGrid = grid;
                for (int k = 0; k < size; k++)
                {
                    copyGrid[i][j] = items[i][j].cd[k];
                    auto itemsNew = buildItems(grid);

                    if (processGrid(copyGrid, itemsNew, loop + 1))
                    {
                        grid = copyGrid;
                        return true;
                    }
                }
                return false;
            }
        }
    }
    return false;
}

bool processGrid(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items, int loop)
{
    processGrid_Strategy_1(items);
    processGrid_Strategy_2(items);

    int total = 0;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (items[i][j].num == 0 && items[i][j].cd.size() == 0)
            {
                return false;
            }

            if (items[i][j].cd.size() == 1 && grid[i][j] == 0)
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

    if (validateGrid(grid))
    {
        return true;
    }

    int minGo = 9;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == 0 && items[i][j].num == 0)
            {
                minGo = min(minGo, (int)items[i][j].cd.size());
            }
        }
    }

    std::cout << "---- PREDICTION via " << minGo << " ----" << std::endl;
    return predictGrid(grid, items, loop, minGo);
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

    int id, sum = 0;
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
        
        sum += (grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2]);
        std::cout << "-- Finish Process Grid - #" << id << " ---" << std::endl << std::endl;
    }

    std::cout << "|-------------------|" << std::endl;
    std::cout << "| Score = (" << id - 1 - failed.size() << " / " << id - 1 << ") |" << std::endl;
    std::cout << "|-------------------|" << std::endl;
    std::cout << "Sum = " << sum << std::endl;
    
    return 0;
}
