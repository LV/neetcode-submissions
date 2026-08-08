class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        std::unordered_map<int, int> instances;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> topK;


        // record number of instances
        for(int i=0; i<nums.size(); i++) {
            unordered_map<int, int>::iterator it = instances.find(nums[i]);

            if (it == instances.end()) {
                instances.insert({nums[i], 1});
            } else {
                it->second++;
            }
        }

        for(auto it = instances.begin(); it != instances.end(); it++) {
            if (topK.size() < k) {
                topK.push({it->second, it->first});
            } else {
                if (it->second > topK.top().first) {
                    topK.pop();
                    topK.push({it->second, it->first});
                }
            }
        }

        while(!topK.empty()) {
            ans.push_back(topK.top().second);
            topK.pop();
        }

        return ans;
    }
};