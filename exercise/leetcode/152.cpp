#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        const int MAX_N = 2e4 + 10;
        const int INF = 0x2FFFFFFF;

        int max_num = nums[0];
        int dp_max[2], dp_min[2];
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int pre = 0;
        int cur = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            dp_max[cur] = std::max(nums[i], nums[i] * dp_max[pre]);
            dp_max[cur] = std::max(dp_max[cur], nums[i] * dp_min[pre]);
            dp_min[cur] = std::min(nums[i], nums[i] * dp_max[pre]);
            dp_min[cur] = std::min(dp_min[cur], nums[i] * dp_min[pre]);

            max_num = std::max(max_num, dp_max[cur]);
            pre ^= 1;
            cur ^= 1;
        }
        return max_num;
    }
};

int main()
{
    std::vector<int> nums = {-2,-3,7};
    Solution solution;
    printf("%d\n", solution.maxProduct(nums));
    return 0;
}
