#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int last=0,curr=1;
        for(int i=1;i<=n;i++){
            int temp=curr+last;
            last=curr;
            curr=temp;
        }
        return last;
    }
};