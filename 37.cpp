 #include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<vector<char> > &board,int q,int w){

        int a[10];
        for(int j=0;j<10;j++){
            a[j]=0;
        }
        for(int j=0;j<9;j++){
            
            if(board[q][j]!='.'){
                if(a[board[q][j]-'0']==0){
                    a[board[q][j]-'0']=1;
                }
                else{
                    return 0;
                }
            }
        }

        for(int i=0;i<10;i++){
            a[i]=0;
        }
        for(int i=0;i<9;i++){
            
            if(board[i][w]!='.'){
                if(a[board[i][w]-'0']==0){
                    a[board[i][w]-'0']=1;
                }
                else{
                    return 0;
                }
            }
        }

        int i=q%3;
        int j=w%3;

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


        return 1;
    }
    bool dfs(vector<vector<char> > &board,int ind){
        if(ind==81){
            return true;
        }
        int x=ind%9;
        int y=ind/9;
        
        if(board[x][y]=='.'){
            for(int n=1;n<10;n++){
                board[x][y]=n+'0';
                if(check(board,x,y)){
                    
                    if(dfs(board,ind+1)){
                        return 1;
                    }
                    
                }
                board[x][y]='.';
            }
        }
        else{
            return dfs(board,ind+1);
        }
        return 0;
    }
    void solveSudoku(vector<vector<char> > &board) {
        dfs(board,0);
    }
};
int main(){
    Solution s;
    vector<vector<char> > board;
    char** b=new char*[9];
    for (int i=0;i<9;i++){
        b[i]=new char[9];
        vector<char> a;
        board.push_back(a);
    }
    b[0]="..9748...";
    b[1]="7........";
    b[2]=".2.1.9...";
    b[3]="..7...24.";
    b[4]=".64.1.59.";
    b[5]=".98...3..";
    b[6]="...8.3.2.";
    b[7]="........6";
    b[8]="...2759..";
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            board[i].push_back(b[i][j]);
        }
    }
    s.solveSudoku(board);
    return 0;
}
