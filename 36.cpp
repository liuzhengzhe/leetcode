class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;i++){
            int *a=new int[10];
            for(int j=0;j<10;j++){
                a[j]=0;
            }
            for(int j=0;j<9;j++){
                
                if(board[i][j]!='.'){
                    if(a[board[i][j]-'0']==0){
                        a[board[i][j]-'0']=1;
                    }
                    else{
                        return 0;
                    }
                }
            }
            delete[] a;
        }
        for(int j=0;j<9;j++){
            int *a=new int[10];
            for(int i=0;i<10;i++){
                a[i]=0;
            }
            for(int i=0;i<9;i++){
                
                if(board[i][j]!='.'){
                    if(a[board[i][j]-'0']==0){
                        a[board[i][j]-'0']=1;
                    }
                    else{
                        return 0;
                    }
                }
            }
            delete[] a;
        }
        for(int j=0;j<3;j++){
            for(int i=0;i<3;i++){
                int *a=new int[10];
                for(int x=0;x<10;x++){
                    a[x]=0;
                }
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){                
                        if(board[i*3+x][j*3+y]!='.'){
                            if(a[board[i*3+x][j*3+y]-'0']==0){
                                a[board[i*3+x][j*3+y]-'0']=1;
                            }
                            else{
                                return 0;
                            }
                        }
                    }
                }
                delete[] a;
            }
        }
        return 1;
    }
};