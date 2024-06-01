#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threesum(vector<int> &nums);

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threesum(nums);
    // printing result
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Solution #" << i + 1 << ": {";
        for (int j = 0; j < 3; j++)
        {
            if (j + 1 == 3)
            {
                cout << result[i][j];
            }
            else
            {
                cout << result[i][j] << ", ";
            }
        }
        cout << "}\n";
    }

    return 0;
}

vector<vector<int>> threesum(vector<int> &nums)
{
    vector<vector<int>> result = {};

    // create a size variable for nums, and check for it being a smaller size then a triplet
    int n = nums.size();
    if (n < 3)
    {
        return result;
    }

    sort(nums.begin(), nums.end());

    // for loop from the beginning of nums to the second to last element
    // remember that there will still be a left and right pointer
    //  so getting to the last element is redundant/not necessary
    for (int i = 0; i < n - 2; i++)
    {
        // make sure you don't get into the positives for your 'a' number
        // since three positive numbers will never equate to zero
        if (nums[i] > 0)
        {
            break;
        }
        // make sure that our 'a' value is not the same as before, to keep from
        // having duplicate solutions
        if ((i > 0) && (nums[i] == nums[i - 1]))
        {
            continue;
        }

        // set up left and right pointers
        // remember that you'll have this set up per iteration of the for loop
        //       [-3,   -3,   1,   2,   3,   4]
        //               i  left           right
        int left = i + 1;
        int right = n - 1;

        // calculate the sum, then the problem becomes twoSum
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum > 0)
            {
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                // also need a check for each left/ right pointer to make sure we don't
                // have duplicate answers, so we'll iterate till the one ahead of it is
                // is not the same
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                left++;
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }
                right--;
            }
        }
    }

    return result;
}