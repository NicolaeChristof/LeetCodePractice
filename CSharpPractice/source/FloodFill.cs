// https://leetcode.com/problems/flood-fill
using System.Collections.Generic;

namespace LeetCodePractice.FloodFill
{
    public class Solution
    {
        public int[][] FloodFill(int[][] image, int sr, int sc, int color)
        {
            int originalColor = image[sr][sc];
            if (originalColor == color) return image;

            int rows = image.Length;
            int cols = image[0].Length;

            Queue<(int, int)> queue = new Queue<(int, int)>();
            queue.Enqueue((sr, sc));

            while (queue.Count > 0)
            {
                var (row, col) = queue.Dequeue();
                image[row][col] = color;

                if (row - 1 >= 0 && image[row - 1][col] == originalColor) queue.Enqueue((row - 1, col));
                if (row + 1 < rows && image[row + 1][col] == originalColor) queue.Enqueue((row + 1, col));
                if (col - 1 >= 0 && image[row][col - 1] == originalColor) queue.Enqueue((row, col - 1));
                if (col + 1 < cols && image[row][col + 1] == originalColor) queue.Enqueue((row, col + 1));
            }

            return image;
        }
    }
}