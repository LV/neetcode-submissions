class Solution {
public:
    void addAtIndex(vector<int>& digits, int idx) {
        if(idx < 0) {
            digits.insert(digits.begin(), 1);
            return;
        }
        
        if(digits[idx] < 9) {
            digits[idx]++;
            return;
        }

        digits[idx] = 0;
        addAtIndex(digits, idx-1);
    }

    vector<int> plusOne(vector<int>& digits) {
        addAtIndex(digits, digits.size()-1);
        return digits;
    }
};