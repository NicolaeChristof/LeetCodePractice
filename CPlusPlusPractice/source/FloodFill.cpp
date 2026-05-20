// https://leetcode.com/problems/flood-fill
#include <vector>
#include <queue>

// BFS solution
class Solution
{
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        const int rows = image.size();
        const int cols = image[0].size();

        std::queue<std::pair<int, int>> q;
        q.emplace(sr, sc);

        while (!q.empty())
        {
            const auto [row, col] = q.front();
            q.pop();
            image[row][col] = color;

            if (row - 1 >= 0 && image[row - 1][col] == originalColor) q.emplace(row - 1, col);
            if (row + 1 < rows && image[row + 1][col] == originalColor) q.emplace(row + 1, col);
            if (col - 1 >= 0 && image[row][col - 1] == originalColor) q.emplace(row, col - 1);
            if (col + 1 < cols && image[row][col + 1] == originalColor) q.emplace(row, col + 1);
        }

        return image;
    }
};

// Recursive solution
//class Solution
//{
//public:
//    void ColorNeighbor(std::vector<std::vector<int>>& image, int sr, int sc, int newColor, int originalColor)
//    {
//        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
//        if (image[sr][sc] == newColor) return;
//
//        if (image[sr][sc] == originalColor)
//        {
//            image[sr][sc] = newColor;
//
//            ColorNeighbor(image, sr - 1, sc, newColor, originalColor);
//            ColorNeighbor(image, sr + 1, sc, newColor, originalColor);
//            ColorNeighbor(image, sr, sc - 1, newColor, originalColor);
//            ColorNeighbor(image, sr, sc + 1, newColor, originalColor);
//        }
//    }
//
//    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
//    {
//        if (image.empty()) return image;
//
//        ColorNeighbor(image, sr - 1, sc, color, image[sr][sc]);
//        ColorNeighbor(image, sr + 1, sc, color, image[sr][sc]);
//        ColorNeighbor(image, sr, sc - 1, color, image[sr][sc]);
//        ColorNeighbor(image, sr, sc + 1, color, image[sr][sc]);
//
//        image[sr][sc] = color;
//
//        return image;
//    }
//};