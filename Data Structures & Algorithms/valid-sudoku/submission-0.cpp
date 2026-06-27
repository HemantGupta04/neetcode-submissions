class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            vector<int>row(10,1);
            vector<int>col(10,1);
            for(int j=0;j<9;j++){
               if(board[i][j]!='.'){
                row[board[i][j]-'0']--;
                if(row[board[i][j]-'0']<0)return false;
               }
               if(board[j][i]!='.'){
                col[board[j][i]-'0']--;
                if(col[board[j][i]-'0']<0)return false;
               }

            }
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int>box(10,1);
                for(int ni=i;ni<i+3;ni++){
                    for(int nj=j;nj<j+3;nj++){
                        if(board[ni][nj]!='.'){
                            box[board[ni][nj]-'0']--;
                            if(box[board[ni][nj]-'0']<0)return false;

                        }
                    }
                }

            }
        }
        return true;
    }
};
