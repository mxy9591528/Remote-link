#include<iostream>
using namespace std;
long long quickpow(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b&1)//���bΪ����
            res=res*a%p;
        a=a*a%p;
        b>>=1;//�൱�ڳ�2
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long a,b,q;
        cin>>a>>b>>q;
        cout<<quickpow(a, b, q)<<endl;
    }
    return 0;
}
