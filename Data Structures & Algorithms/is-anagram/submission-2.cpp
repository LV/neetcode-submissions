class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int arr[26] = {};

        for (char c : s) {
            arr[c - 'a'] += 1;
        }

        for (char c : t) {
            if (arr[c - 'a'] ==  0) {
                return false;
            }
            arr[c - 'a'] -= 1;
        }

        return true;
    }
};
