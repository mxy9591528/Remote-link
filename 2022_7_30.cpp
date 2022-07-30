#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010];//正整数的值
int mi=1e9;
//判断是否为质数
bool primer(int x){
   for(int i=2;i*i<=x;i++){
       if(x%i==0){
           return false;
       }
   }
    return true;
}
void dfs(int x,set<int> s,int temp){
    if(x==n){
        mi=min(mi,temp);
        return;
    }
    for(int i=2;i<=a[x];i++){
        if(a[x]%i==0 && primer(i)&&!s.count(i)){
            s.insert(i);
            dfs(x+1,s,temp+i);
            s.erase(i);
        }
    }
}
int  main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int> s;
    dfs(0,s,0);
    if(mi==1e9)cout<<-1;
    else cout<<mi;
    return 0;
    
}


