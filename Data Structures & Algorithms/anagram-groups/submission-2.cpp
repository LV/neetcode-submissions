class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> grouped_words;

        for (const string& str : strs) {
            std::string copyStr = str;
            std::sort(copyStr.begin(), copyStr.end());

            auto it = grouped_words.find(copyStr);

            if (it == grouped_words.end()) {
                grouped_words.insert({copyStr, {str}});
                continue;
            }

            it->second.push_back(str);
        }

        std::vector<std::vector<string>> final_grouped_words;
        for (const auto& entry : grouped_words) {
            final_grouped_words.push_back(entry.second);
        }

        return final_grouped_words;
    }
};
