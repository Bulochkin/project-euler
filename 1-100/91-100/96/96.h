#pragma once
#define GRID_SIZE 9

namespace euler_96
{
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
                    continue;
                }
            }
        }
        return items;
    }

    void processGrid_Step_1(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items)
    {
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                for (int r = 0; r < GRID_SIZE; r++)
                {
                    if (grid[i][r] != 0 && r != j)
                    {
                        auto it = std::remove(items[i][j].cd.begin(), items[i][j].cd.end(), grid[i][r]);
                        items[i][j].cd.erase(it, items[i][j].cd.end());
                    }
                }

                for (int c = 0; c < GRID_SIZE; c++)
                {
                    if (grid[c][j] != 0 && c != i)
                    {
                        auto it = std::remove(items[i][j].cd.begin(), items[i][j].cd.end(), grid[c][j]);
                        items[i][j].cd.erase(it, items[i][j].cd.end());
                    }
                }

                for (int is = 3 * (i / 3); is < 3 * (i / 3) + 3; is++)
                {
                    for (int js = 3 * (j / 3); js < 3 * (j / 3) + 3; js++)
                    {
                        if (is != i && js != j && grid[is][js] != 0)
                        {
                            auto it = std::remove(items[i][j].cd.begin(), items[i][j].cd.end(), grid[is][js]);
                            items[i][j].cd.erase(it, items[i][j].cd.end());
                        }
                    }
                }
            }
        }
    }

    void processGrid_Step_2(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items)
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

    void processGrid_Step_3(std::vector<std::vector<int>>& grid, std::vector<std::vector<item>>& items)
    {
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (items[i][j].num != 0)
                {
                    continue;
                }

                const auto& toSearch = items[i][j].cd;
                if (toSearch.size() < 2)
                {
                    continue;
                }

                for (auto num : toSearch)
                {
                    int total = 0;
                    for (int k = 0; k < GRID_SIZE; k++)
                    {
                        if (items[i][k].num == 0)
                        {
                            auto it = std::find(items[i][k].cd.begin(), items[i][k].cd.end(), num);
                            if (it != items[i][k].cd.end())
                            {
                                total++;
                            }
                        }
                    }

                    if (total != 1)
                    {
                        break;
                    }

                    total = 0;
                    for (int k = 0; k < GRID_SIZE; k++)
                    {
                        if (items[k][j].num == 0)
                        {
                            auto it = std::find(items[k][j].cd.begin(), items[k][j].cd.end(), num);
                            if (it != items[k][j].cd.end())
                            {
                                total++;
                            }
                        }
                    }

                    if (total != 1)
                    {
                        break;
                    }

                    total = 0;
                    for (int is = 3 * (i / 3); is < 3 * (i / 3) + 3; is++)
                    {
                        for (int js = 3 * (j / 3); js < 3 * (j / 3) + 3; js++)
                        {
                            if (items[is][js].num == 0)
                            {
                                auto it = std::find(items[is][js].cd.begin(), items[is][js].cd.end(), num);
                                if (it != items[is][js].cd.end())
                                {
                                    total++;
                                }
                            }
                        }
                    }

                    if (total == 1)
                    {
                        items[i][j].cd = { num };
                    }

                    break;
                }
            }
        }
    }
}
