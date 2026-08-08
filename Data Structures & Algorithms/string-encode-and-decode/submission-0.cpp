class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(const string& s : strs) {
            ans += to_string(s.size());
            ans += ".";
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int parse_start_index = 0;

        cout << s << endl;

        for(int i=0; i<s.size(); i++) {
            cout << s[i] << endl;
            if(s[i] != '.') {
                continue;
            }
            int word_length = stoi(s.substr(parse_start_index, i));
            cout << s.substr(i+1, word_length) << endl;
            ans.push_back(s.substr(i+1, word_length));
            cout << "HELLO" << endl;
            cout << i << endl;
            i += word_length + 1;
            cout << s[i];
            parse_start_index = i;
        }

        return ans;
    }
};
