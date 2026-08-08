class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        std::unordered_map<int, int> instances;  // records amount of times number shows up

        for (int i=0; i<nums.size(); i++) {
            unordered_map<int, int>::iterator it = seen.find(target - nums[i]);

            // found a match!
            if (it != seen.end()) {
                return {it->second, i};
            }

            // add the current number to `seen` if it doesn't already exist
            it = seen.find(nums[i]);
            if (it == seen.end()) {
                seen.insert({nums[i], i});
            }
        }
        return {};
    }
};