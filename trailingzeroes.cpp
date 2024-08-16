#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void takeinput(){
   #ifndef ONLINE_JUDGE
    freopen("D:\\coding\\input.txt","r",stdin);
    freopen("D:\\coding\\output.txt","w",stdout);
    #endif
}
int fac(int n){
    if(n==0) return 1;
    return n*fac(n-1);
}
int main()
{
    takeinput();
    // Your code here
    int n;
    cin>>n;
    if (n < 0) return -1;
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) count += n / i;
    cout<<count;
}