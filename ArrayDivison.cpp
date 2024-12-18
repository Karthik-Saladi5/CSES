#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define pb push_back
#define F first
#define S second
#define SQ(a) (a)*(a)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define ALL(a) (a).begin(), (a).end()
const int mod = 1000000007;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define tc\
    int t;\
    cin>>t;\
    while(t--)
void takeinput(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\coding\\input.txt","r",stdin);
    freopen("D:\\coding\\output.txt","w",stdout);
    freopen("D:\\coding\\error.txt","w",stderr);
    #endif
}
void sk(){
    // Your code goes here
    ll n; cin >> n;
    vi arr(n);
    ll k; cin >> k;
    ll low = -1;// as single
    ll high = 0; // as whole
    for (auto& i : arr) {
        cin >> i;
        low = max(low, i);
        high += i;
    }
    while (low < high) {
        ll mid = low + (high - low) / 2;
        ll c = 1, sum = 0;
        for (auto i : arr) {
            if(sum+i>mid){
                sum = i;
                c++;
            }
            else {
                sum += i;
            }
        }
        if (c > k) low = mid+1;
        else high = mid;
    }
    cout << high;
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   takeinput();
    sk();
    return 0;
}