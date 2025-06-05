#include <bits/stdc++.h>
using namespace std;

const int MAXN=1001;
int ele[MAXN],seg[4*MAXN];

void build(int index,int low,int high){
    if(low == high) {
        seg[index] = ele[high];
        return;
    }
    int mid= (low+high)/2;
    build(2*index+1,low,mid);
    build(2*index+2,mid+1,high);
    seg[index] = min( seg[2*index+1],seg[2*index+2]);
}

int  query(int ind,int low,int high,int l,int r){
    if(l<=low && high<=r) return seg[ind];
    if(r<low || high<l) return INT_MAX;
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>ele[i];
    }
    build(0,0,n-1);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int mn_q=query(0,0,n-1,l,r);
        cout<<mn_q<<'\n';
    }

    return 0;

}
