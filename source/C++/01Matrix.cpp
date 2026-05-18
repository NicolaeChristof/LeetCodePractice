// https://leetcode.com/problems/01-matrix
#include <vector>
#include <queue>

class Solution
{
    const std::vector<std::pair<int, int>> neighbors = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
    {
        std::queue<std::pair<int, int>> q;

        // prefil queue with positions equal to 0
        for (int row = 0; row < mat.size(); ++row)
        {
            for (int col = 0; col < mat[0].size(); ++col)
            {
                if (mat[row][col] == 0)
                {
                    q.emplace(row, col);
                }
                else
                {
                    mat[row][col] = INT_MAX;
                }
            }
        }

        while (!q.empty())
        {
            const auto [x, y] = q.front();
            q.pop();

            for (const auto& [deltaX, deltaY] : neighbors)
            {
                int newRow = x + deltaX;
                int newCol = y + deltaY;

                if (newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size())
                {
                    if (mat[newRow][newCol] > mat[x][y] + 1)
                    {
                        mat[newRow][newCol] = mat[x][y] + 1;
                        q.emplace(newRow, newCol);
                    }
                }
            }
        }

        return mat;
    }
};