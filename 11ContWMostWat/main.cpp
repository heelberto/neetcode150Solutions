#include <iostream>
#include <vector>

int brute_maxArea(const std::vector<int> &height);

int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int answer = 0;
    answer = brute_maxArea(height);

    std::cout << "Max area of height: " << answer << std::endl;

    return 0;
}

int brute_maxArea(const std::vector<int> &height)
{
    int area = 0, result = 0;

    for (int l = 0; l < height.size(); l++)
    {
        for (int r = l + 1; height.size(); r++)
        {
            area = (r - l) * std::min(height[r], height[l]);
            result = std::max(area, result);
        }
    }

    return area;
}