// https://leetcode.com/problems/number-of-islands
#include <vector>
#include <queue>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        if (grid.empty()) return 0;

        int numIslands = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++numIslands;
                    // remove all connected land
                    DFS(grid, i, j);
                    //BFS(grid, i, j);
                }
            }
        }

        return numIslands;
    }
private:
    const std::vector<std::pair<int, int>> neighbors = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    // Recursive DFS
    void DFS(std::vector<std::vector<char>>& grid, const int x, const int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') return;

        grid[x][y] = '0';

        for (const auto [deltaX, deltaY] : neighbors)
        {
            DFS(grid, x + deltaX, y + deltaY);
        }
    }

    // Iterative BFS (could also swap queue with stack for iterative DFS)
    void BFS(std::vector<std::vector<char>>& grid, const int startX, const int startY)
    {
        std::queue<std::pair<int, int>> q;

        q.emplace(startX, startY);
        grid[startX][startY] = '0';

        while (!q.empty())
        {
            const auto [x, y] = q.front();
            q.pop();

            for (const auto [deltaX, deltaY] : neighbors)
            {
                const int newX = x + deltaX;
                const int newY = y + deltaY;

                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size())
                {
                    if (grid[newX][newY] == '1')
                    {
                        grid[newX][newY] = '0';
                        q.emplace(newX, newY);
                    }
                }
            }
        }
    }
};