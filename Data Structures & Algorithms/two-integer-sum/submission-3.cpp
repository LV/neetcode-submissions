class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visited;  // {num, index}

        for (int i = 0; i < nums.size(); ++i) {
            auto it = visited.find(target - nums[i]);
            if (it != visited.end()) {
                return {it->second, i};
            }

            visited.insert({nums[i], i});
        }

        return {};
    }
};
