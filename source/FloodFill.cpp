// https://leetcode.com/problems/flood-fill
#include <vector>

class Solution
{
public:
    void ColorNeighbor(std::vector<std::vector<int>>& image, int sr, int sc, int newColor, int originalColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if (image[sr][sc] == newColor) return;

        if (image[sr][sc] == originalColor)
        {
            image[sr][sc] = newColor;

            ColorNeighbor(image, sr - 1, sc, newColor, originalColor);
            ColorNeighbor(image, sr + 1, sc, newColor, originalColor);
            ColorNeighbor(image, sr, sc - 1, newColor, originalColor);
            ColorNeighbor(image, sr, sc + 1, newColor, originalColor);
        }
    }

    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        if (image.empty()) return image;

        ColorNeighbor(image, sr - 1, sc, color, image[sr][sc]);
        ColorNeighbor(image, sr + 1, sc, color, image[sr][sc]);
        ColorNeighbor(image, sr, sc - 1, color, image[sr][sc]);
        ColorNeighbor(image, sr, sc + 1, color, image[sr][sc]);

        image[sr][sc] = color;

        return image;
    }
};