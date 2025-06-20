#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int steps(int n, long pref1, long pref2){
        int res=0;
        while(pref1<=n){
            res+=min((long)(n+1),pref2)-pref1;
            pref1*=10;
            pref2*=10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
        int res=1;
        k--;
        while(k){
            int step=steps(n,res,res+1);
            if(step<=k){
                res++;
                k-=step;
            }else{
                res*=10;
                k--;
            }
        }
        return res;
    }
};