#include<bits/stdc++.h>
using namespace std;

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s=*max_element(boards.begin(),boards.end());
    int e=accumulate(boards.begin(),boards.end(),0);
    while(s<=e){
        int m=s+(e-s)/2;
        int numP=1,sum=0;
        for(int x:boards){
            sum+=x;
            if(sum>m){
                sum=x;
                numP++;
            }
        }
        if(numP>k) s=m+1;
        else e=m-1;
    }
    return s;
}