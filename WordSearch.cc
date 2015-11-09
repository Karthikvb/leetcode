class WordSearch {
public:
    bool check(vector<vector<char>>& board, string word, int i, int j, int pos) {
        if (word.size() == pos) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return false;
        }
        char c = board[i][j];
        if (c == word[pos]) {
            board[i][j] = '#';
            if (check(board, word, i-1, j, pos+1)) {
                return true;
            }
            if (check(board, word, i+1, j, pos+1)) {
                return true;
            }
            if (check(board, word, i, j-1, pos+1)) {
                return true;
            }
            if (check(board, word, i, j+1, pos+1)) {
                return true;
            }
            board[i][j] = c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       if (!word.size() || !board.size()) {
           return false;
       }
       for (int i = 0; i < board.size(); i++) {
           for (int j = 0; j < board[i].size(); j++) {
               // operate on board[i][j] ?
               if (check(board, word, i, j, 0)) {
                   return true;
               }
           }
       }
       return false;
    }
};
