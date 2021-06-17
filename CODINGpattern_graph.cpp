/*Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
*/

#include<bits/stdc++.h>
using namespace std;

//mov array represent all 8 direction move
int mov[8][2]={{-1,-1},{0,-1},{-1,1},{1,0},{1,1},{0,1},{-1,0},{-1,1}};
//word array represent the all character of the word
char word[11]={'C','O','D','I','N','G','N','I','N','J','A'};
//visited array is used for maintainning the visited position
int visited[1001][1001]={0};


bool valid(int x,int y,int n,int m)
{
    //cheching the valid index condition
    if(x>=0 and x<n and y>=0 and y<m)
        return true;
    return false;
}
//traverse in the DFS form
int DFS(vector<vector<char>> &board,int x,int y,int n,int m,int index)
{
    //final goal
    if(index==11)
        return 1;
    
    visited[x][y]=1;//visited 2D array marked
    int t_x,t_y,found=0;
    for(int i=0;i<8;i++)
    {
        t_x=x+mov[i][0];//move's
        t_y=y+mov[i][1];//move's
        if(valid(t_x,t_y,n,m)==true and board[t_x][t_y]==word[index] and visited[t_x][t_y]!=1)
        {
            found=found|DFS(board,t_x,t_y,n,m,index+1); 
            
        }
    }
    
    visited[x][y]=0;//visited 2D array unmarked
    return found;//return the result
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    int i,j,found=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='C')
            {
                found=DFS(board,i,j,n,m,1);
               
            }
            if(found==1)
                    break;
        }
         if(found==1)
                    break;
    }
    return found;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
