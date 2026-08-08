class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int hasher = 0;
        for(int i=0; i<nums.size(); i++) {
            hasher ^= nums[i];
        }

        return hasher;
    }
};