class Solution {
public:
    int size,n,m;
    bool solve(vector<vector<char>> &board, string word, int ind, int i, int j) {
        if(ind==size) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[ind])return false;
        char ch=board[i][j];
        board[i][j]='*';
        bool ans = solve(board,word,ind+1,i+1,j) | solve(board,word,ind+1,i,j+1) | solve(board,word,ind+1,i,j-1) | solve(board,word,ind+1,i-1,j);
        board[i][j]=ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        size=word.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(solve(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};