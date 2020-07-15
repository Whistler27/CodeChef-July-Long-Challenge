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

ll mpow(ll base,ll exp);
ll POW(ll base,ll exp);
ll gcd(ll a,ll b);
ll modInverse(ll n);
ll nCr(ll n, ll r);

int CeilIndex(std::vector<int>& v, int l, int r, int key){ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
    return r; 
} 
  
int LongestIncreasingSubsequenceLength(std::vector<int>& v, ll a[]) { 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; 
    ll ans=0;
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i],ans+=a[i]; 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return ans;
}

void solve(){
    ll n,q;
    cin >> n >> q;
    ll h[n],arr[n];
    loop(i,0,n) cin >> h[i];
    loop(i,0,n) cin >> arr[i];

    while(q--){
        ll num,a,b;
        cin >> num >> a >> b;
        a--,b--;
        if(num==1){
            b++;
            arr[a]=b;
        }
        else{
            ll ma=0;
            ll p=0;
            ll pq=min(a,b);
            ll pw=max(a,b);
            loop(i,pq+1,pw){
                if(h[i]>ma){
                    ma=h[i];
                }
            }

            if(ma >=max(h[a],h[b])){
                cout << -1 << endl;
                continue;
            }
            ll ans=0;
            ll prev=0;
            ans+=arr[a];
            ans+=arr[b];
            //cout << ans << endl;
            if(a==b) ans=arr[a];
            if(h[a]==h[b] && a!=b) ans=-1;
            //cout << h[a] << " " << h[b] << endl;
            if(h[b]>h[a]){
            ans=-1;
        }
        else if(h[a]>h[b]){
            if(a<b){
                prev=h[b];
                epool(i,b-1,a+1){
                    if(h[i]>prev && h[i]<h[a]){
                        prev=h[i];
                        ans+=arr[i];
                    }

                }

            }
            else{
                prev=h[b];
                loop(i,b+1,a){
                //cout << prev << " ";
                if(h[i]>prev && h[i]<h[a]){
                    prev=h[i];
                    ans+=arr[i];
                    }
                }

            }

        }
            cout << ans << endl;

        }
    }

}

int32_t main(){
    SpeedForce
    ll i = 0,j = 0;



    int t;
    t=1;
    //cin >> t;
    //ll cnt=1;
    while (t--){
        //cout << "Case #" << cnt << ": ";
        //cout << fixed << setprecision(10);
        solve();
        //cout << endl;
        //cnt++;
    }
}

ll POW(ll base,ll exp){
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base);
        base = ((ll)base * base);
        exp >>= 1;
    }
    return result;
}

ll mpow(ll base, ll exp){
    base %= mod;
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll modInverse(ll n) { 
    return mpow(n, mod-2); 
}
 
ll nCr(ll n, ll r){ 
   if (r==0) 
      return 1; 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = (fac[i-1]*i)%mod; 
    return ((fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) % mod)%mod)%mod; 
}