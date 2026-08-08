class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check Rows
        for(int i=0; i<board.size(); i++) {
            vector<int> visited(9, 0);
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == '.') {
                    continue;
                }

                int c = static_cast<int>(board[i][j]) - '0';
                if(visited[c-1] != 0) {
                    return false;
                }

                visited[c-1] = 1;
            }
        }

        // Check Columns
        for(int i=0; i<board.size(); i++) {
            vector<int> visited(9, 0);

            for(int j=0; j<board[0].size(); j++) {
                if(board[j][i] == '.') {
                    continue;
                }

                int c = static_cast<int>(board[j][i]) - '0';
                if(visited[c-1] != 0) {
                    return false;
                }

                visited[c-1] = 1;
            }
        }

        // Check Boxes
        for(int i=0; i<board.size(); i++) {
            vector<int> visited(9, 0);

            for(int j=0; j<board[0].size(); j++) {
                if(board[((i/3)*3)+(j/3)][((i%3)*3)+(j%3)] == '.') {
                    continue;
                }

                int c = static_cast<int>(board[((i/3)*3)+(j/3)][((i%3)*3)+(j%3)]) - '0';
                if(visited[c-1] != 0) {
                    return false;
                }

                visited[c-1] = 1;
            }
        }

        return true;
    }
};
