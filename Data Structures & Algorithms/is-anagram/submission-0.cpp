class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        std::unordered_map<char, int> table;

        for(int i=0; i<s.size(); i++) {
            std::unordered_map<char, int>::iterator it = table.find(s[i]);
            if(table.find(s[i]) == table.end()) {
                table.insert({s[i], 1});
            }
            else {
                it->second++;
            }
        }


        for(int i=0; i<t.size(); i++) {
            std::unordered_map<char, int>::iterator it = table.find(t[i]);
            if(table.find(t[i]) == table.end()) {
                return false;
            }

            if(it->second <= 0) {
                return false;
            }

            it->second--;
        }

        for(const std::pair<char, int>& entry : table) {
            if(entry.second != 0) {
                return false;
            }
        }

        return true;
    }
};