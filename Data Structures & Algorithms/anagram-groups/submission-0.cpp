class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) {
            return {{}};
        }

        if (strs.size() == 1) {
            return {{ strs[0] }};
        }

        std::unordered_map<string, vector<string>> groups;

        for (int i=0; i<strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());

            auto it = groups.find(key);

            if (it == groups.end()) {
                groups.insert({key, {strs[i]}});
            } else {
                (it->second).push_back(strs[i]);
            }
        }

        std::vector<vector<string>> ans;
        for (auto it = groups.begin(); it != groups.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};