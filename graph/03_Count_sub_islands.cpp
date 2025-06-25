#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x,int y, vector<vector<int>> &g){
        g[x][y]=0;
        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<g.size()&&ny>=0&&ny<g[0].size()&&g[nx][ny]) dfs(nx,ny,g);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]&&!grid1[i][j]){
                    dfs(i,j,grid2);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid2[i][j]) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                grid2[i][j]=0;
                res++;
                while(q.size()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    vector<int> dx={0,0,-1,1};
                    vector<int> dy={1,-1,0,0};
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i],ny=y+dy[i];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid2[nx][ny]) {
                            q.push({nx,ny});
                            grid2[nx][ny]=0;
                        }
                    }
                }
            }
        }
        return res;
    }
};