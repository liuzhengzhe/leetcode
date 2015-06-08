#include <iostream>
using namespace std;
#include <vector>
//accepted
class Solution {
public:
    bool dfs(int cur,string word,int i,int j,vector<vector<char> > &board,vector<vector<char> > &en){
        if(i < 0 || i >= board.size()  
            || j < 0 || j>=board[0].size() 
            || en[i][j] == 1){  
            return false;  
        }  
        if(board[i][j] != word[cur-1]){  
            return false;  
        }  
        if(cur==word.length()){
            return 1;
        }
        int b=0;
        en[i][j]=1;
        bool flag = dfs(cur+1, word, i - 1, j, board,en)   
            || dfs(cur+1, word, i + 1, j, board,en)   
            || dfs(cur+1, word, i, j-1, board,en)   
            || dfs(cur+1, word, i, j+1, board,en);   
        en[i][j]=0;
        return flag;
    }
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<char> > en=board;
        /*int c=board.size();
        int d=board[0].size();
        if(c*d<word.length()){
            return false;
        }*/
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                en[i][j]=0;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(1,word,i,j,board,en)){
                        return 1;
                    }
                    
                }
            }
        }
        return 0;
    }
};

//exceed time
class Solution {
public:
    bool dfs(int cur,string word,int i,int j,vector<vector<char> > &board,vector<vector<char> > &en){
        if(cur==word.length()-1){
            if(word[cur]==board[i][j]){
                return 1;
            }
        }
        int b=0;
        if(i>0 and board[i-1][j]==word[cur] and en[i-1][j]==0){
            en[i-1][0]=1;
            if(dfs(cur+1,word,i-1,j,board,en)){
                b=1;
            }
            en[i-1][0]=0;
        }
        if(j>0 and board[i][j-1]==word[cur] and en[i][j-1]==0){
            en[i][j-1]=1;
            if(dfs(cur+1,word,i,j-1,board,en)){
                b=2;
            }
            en[i][j-1]=0;
        }
        if(i<board.size()-1 and board[i+1][j]==word[cur] and en[i+1][j]==0){
            en[i+1][j]=1;
            if(dfs(cur+1,word,i+1,j,board,en)){
                b=3;
            }
            en[i+1][j]=0;
        }
        if(j<board[0].size()-1 and board[i][j+1]==word[cur] and en[i][j+1]==0){
            en[i][j+1]=1;
            if(dfs(cur+1,word,i,j+1,board,en)){
                b=4;
            }
            en[i][j+1]=0;
        }
        if(b==0){
            return false;
        }
    }
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<char> > en=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                en[i][j]=0;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(0,word,i,j,board,en)){
                        return 1;
                    }
                    
                }
            }
        }
        return 0;
    }
};
int main(){
    Solution s;
    vector<vector<char> > a;
    char q[2]={'a','b'};
    vector<char> b(&q[0],&q[2]);
    a.push_back(b);
    s.exist(a, "ab");
    return 0;
}