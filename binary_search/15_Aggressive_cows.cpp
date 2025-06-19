#include<bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int s=1,e=stalls.back()-stalls[0];
    while(s<=e){
        int m=s+(e-s)/2;
        int lastPos=stalls[0],cows=1;
        for(int x:stalls){
            int d=x-lastPos;
            if(d>=m){
                cows++;
                lastPos=x;
            }
        }
        if(cows>=k) s=m+1;
        else e=m-1;
    }
    return e;
}