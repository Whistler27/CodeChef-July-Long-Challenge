#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
 
#define endl '\n'
#define loop(i, m, n) for (ll i = m; i < n; i++)
#define loope(i, m, n) for (ll i = m; i <= n; i++)
#define epool(i, m, n) for (ll i = m; i >= n; i--)
#define mod 1000000007
#define mod2 998244353
#define vi vector<ll>
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define empf emplace_front
#define empb emplace_back
#define ret(x) return cout << x,0;
#define all(v) v.begin(),v.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>
const ll INF=1e18;
const double PI=4*atan(1);

#define SpeedForce                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    loop(i,0,n) cin >> v[i];

    ll ans=0;
    loop(i,1,n){
        ans+=abs(v[i]-v[i-1])-1;

    }
    cout << ans << endl;

}

int32_t main(){
    SpeedForce
    ll i = 0,j = 0;


    int t;
    t=1;
    cin >> t;
    while (t--){
        //cout << fixed << setprecision(10);
        solve();
    }
}
