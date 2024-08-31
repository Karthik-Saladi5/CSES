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
    #endif
}
void buildTree(vi& a,ll ind, ll start, ll end, vi& segementTree) {
    if (start == end) {
        segementTree[ind] = a[start];
        return;
    }
    ll mid = (start + end) >> 1;
    buildTree(a, 2 * ind, start, mid, segementTree);
    buildTree(a, 2 * ind + 1, mid + 1, end, segementTree);
    segementTree[ind] = min(segementTree[2 * ind], segementTree[2 * ind + 1]);
}
ll querySearch(vi& segmentTree, ll qs, ll qe, ll ss, ll se, ll ind) {
    // no overlap
    if (qe<ss || qs>se) return INT_MAX;
    // complete overlap
    if (qs <= ss && qe >= se) return segmentTree[ind];
    //partial overlap
    int mid = (ss + se) >> 1;
    int left = querySearch(segmentTree, qs, qe, ss, mid, 2 * ind);
    int right = querySearch(segmentTree, qs, qe, mid + 1, se, 2 * ind + 1);
    return min(left, right);
}
void update(vi& segmentTree, ll ss, ll se, ll pos, ll val, ll ind) {
    if (ss == se) {
        segmentTree[ind] = val;
        return;
    }
    ll mid = (ss + se) >> 1;
    if (pos <= mid) update(segmentTree, ss, mid, pos, val, 2 * ind);
    else update(segmentTree, mid+1, se, pos, val, 2 * ind + 1);
    segmentTree[ind] = min(segmentTree[2 * ind], segmentTree[2 * ind + 1]);
}
void sk() {
    // Your code goes here
    ll n, q; cin >> n >> q;
    vi a(n);
    for (auto& i : a) cin >> i;
    vi segementTree(4 * n,INT_MAX);
    buildTree(a, 1, 0, n - 1, segementTree);
    while (q--) {
        ll para; cin >> para;
        if (para==1) {
            ll val, pos;
            cin >> pos >> val;
            update(segementTree, 0, n - 1, pos-1, val, 1);
        }
        else {
            ll queryStart; cin >> queryStart;
            ll queryEnd; cin >> queryEnd;
            ll ans = querySearch(segementTree, queryStart - 1, queryEnd - 1, 0, n - 1, 1);
            cout << ans << endl;
        }
    }
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