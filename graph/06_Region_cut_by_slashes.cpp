#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &g){
        g[x][y]=0;
        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<g.size()&&ny>=0&&ny<g.size()&&g[nx][ny]) dfs(nx,ny,g);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> g(3*n,vector<int>(3*m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    int r=3*i,c=3*j;
                    g[r][c+2]=g[r+1][c+1]=g[r+2][c]=0;
                }else if(grid[i][j]=='\\'){
                    int r=3*i,c=3*j;
                    g[r][c]=g[r+1][c+1]=g[r+2][c+2]=0;
                }
            }
        }
        int res=0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*m;j++){
                if(g[i][j]){
                    res++;
                    dfs(i,j,g);
                }
            }
        }
        return res;
    }
};