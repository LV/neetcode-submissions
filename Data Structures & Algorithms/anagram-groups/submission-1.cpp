class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> grouped_words;

        for (string str : strs) {
            std::string original_str = str;
            std::sort(str.begin(), str.end());

            auto it = grouped_words.find(str);

            if (it == grouped_words.end()) {
                grouped_words.insert({str, {original_str}});
                continue;
            }

            it->second.push_back(original_str);
        }

        std::vector<std::vector<string>> final_grouped_words;
        for (auto it = grouped_words.begin(); it != grouped_words.end(); ++it) {
            final_grouped_words.push_back(it->second);
        }

        return final_grouped_words;
    }
};
