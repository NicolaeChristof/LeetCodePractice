// https://leetcode.com/problems/rotting-oranges
#include <vector>
#include <queue>

class Solution
{
    const std::vector<std::pair<int, int>> neighbors = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
public:
    int orangesRotting(std::vector<std::vector<int>>& grid)
    {
        std::queue<std::pair<int, int>> q;
        int freshOranges = 0;

        // Queue starts with all rotting oranges
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2) q.emplace(i, j);
                else if (grid[i][j] == 1) ++freshOranges;
            }
        }

        if (freshOranges == 0) return 0;

        int minutes = 0;
        while (!q.empty())
        {
            bool rotting = false;

            const int qSize = q.size();
            for (int i = 0; i < qSize; ++i)
            {
                const auto [x, y] = q.front();
                q.pop();

                for (const auto [deltaX, deltaY] : neighbors)
                {
                    const int newX = x + deltaX;
                    const int newY = y + deltaY;

                    if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() || grid[newX][newY] != 1) continue;

                    grid[newX][newY] = 2;
                    q.emplace(newX, newY);
                    --freshOranges;
                    rotting = true;
                }
            }
            if (rotting) ++minutes;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};