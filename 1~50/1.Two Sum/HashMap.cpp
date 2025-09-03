#include <vector>
#include <unordered_map>

class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;    // key: number，value: index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // 尋找是否有與 nums[i] 對應的 complement 在 unordered_map 中
            auto it = num_map.find(complement);    

            // 找到且在 unordered_map 的範圍內
            if (it != num_map.end()) {     // num_map.end(): 最後一個元素的下一個，代表 unordered_map 的範圍外
                return {it->second, i};    // it->second: complement 的索引
            }

            // 沒找到就把 nums[i] 當 key (map 的 index), i 當 value 存入 map 中
            num_map[nums[i]] = i;
        }
        return {};
    }
};