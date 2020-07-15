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

ll s(ll n){
    ll ans=0;
    while(n>0){
        ans+=(n%10);
        n=n/10;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll a[n],b[n];
    ll p=0,q=0;
    loop(i,0,n){
        cin >> a[i] >> b[i];
        ll l=s(a[i]);
        ll r=s(b[i]);
        if(l>r) p++;
        else if(r>l) q++;
        else p++,q++;
    }

    if(p>q){
        cout << 0 << " " << p << endl;
    }
    else if(q>p) cout << 1 << " " << q << endl;
    else cout << 2 << " " << p << endl;

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
