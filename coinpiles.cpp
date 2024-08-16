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
int main()
{
    //takeinput();
    // Your code here
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(max(a,b)>2*min(a,b)) cout<<"NO";
        else{
            if((a+b)%3==0) cout<<"YES";
            else cout<<"NO";
        }
        cout<<endl;
    }
}