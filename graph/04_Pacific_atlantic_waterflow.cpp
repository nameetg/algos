#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> a(n,vector<int>(m,0));
        vector<vector<int>> p(n,vector<int>(m,0));
        function<void(bool)> bfs=[&](bool flag){
            vector<vector<int>> v(n,vector<int>(m,0));
            queue<pair<int,int>> q;
            vector<int> dx={0,0,-1,1};
            vector<int> dy={1,-1,0,0};
            if(flag){
                for(int i=1;i<n;i++) q.push({i,0});
                for(int i=1;i<m;i++) q.push({0,i});
                q.push({0,0});
            }
            else{
                for(int i=0;i<n-1;i++) q.push({i,m-1});
                for(int i=0;i<m-1;i++) q.push({n-1,i});
                q.push({n-1,m-1});
            }
            while(q.size()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                v[x][y]=1;
                if(flag) p[x][y]=1;
                else a[x][y]=1;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!v[nx][ny]&&heights[nx][ny]>=heights[x][y]) q.push({nx,ny});
                }
            }
        };
        bfs(1);
        bfs(0);
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]&&p[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};