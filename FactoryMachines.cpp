#include <bits/stdc++.h>
using namespace std;
/*<-------alternates---------->*/
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pi;
#define pb push_back
#define F first
#define S second
#define int ll
/*<--------------------------->*/
/*<----method shortcuts------->*/
#define SQ(a) (a)*(a)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define ALL(a) (a).begin(), (a).end()
#define fixed(n) fixed<<setprecision(n)
#define middle low+(high-low)/2
/*<---------------------------------->*/
/*<------------input----------------->*/
template <class ...As> auto& read(As &...as) { return (cin >> ... >> as); }
template <class T> auto &operator>>(istream &is, vector<T> &xs) {
    for (auto &x : xs) is >> x;
    return is;
}
#define In(...)             __VA_ARGS__; read(__VA_ARGS__)
#define ArIn(name, ...)  name(__VA_ARGS__); cin >> name
/*<----------------------------------->*/
/*<------------output----------------->*/
template <class ...As> auto& write(As ...as) {return (cout << ... << as);}
template <class T> auto& operator<<(ostream& os, const vector<T>& xs) { for (const auto& x : xs) os << x << ' '; return os;}
#define Out(...)              write(__VA_ARGS__)
/*<------------debug----------------->*/

/*<----------------------------------->*/
/*<----user defined defaults---------->*/
const int mod = 1000000007;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define tc\
    int t;\
    cin>>t;\
    while(t--)
void takeinput(){
    #ifndef ONLINE_JUDGE
    freopen("D:/coding/input.txt","r",stdin);
    freopen("D:/coding/output.txt","w",stdout);
    freopen("D:/coding/error.txt","w",stderr);
    #endif
}
///// be an EGOIST/////////////////////////////
void sk() {
    // Your code goes here
    ll In(n, t);
    vi ArIn(a, n);
    ll mn = *min_element(ALL(a));
    ll low = mn, high = t * mn,ans=-1;
    while (low <= high) {
        ll mid = middle;
        ll products = 0;
        for (auto i : a) {
            products += floor(mid / i);
        }
        if (products >=t) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    Out(ans);

}
///// be an EGOIST/////////////////////////////
#undef int
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   takeinput();
//    tc 
   sk();
   return 0;
}