#include <bits/stdc++.h>
using namespace std;


// ============================== Utilities ======================================

using ll = long long;
using ull = unsigned long long ;
using ui = unsigned int;
# define sorte(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
#define revloop(i,n,a) for(int i=n;i>=a;i--)
#define read(arr) for(auto &it:arr) cin>>it;
# define print(arr,n)  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
# define cout(n) cout<<n<<endl;
# define reverse(s) reverse(s.begin(),s.end());   
#define pb push_back
#define mkp make_pair
#define YES  cout << "YES" << endl;
#define NO   cout << "NO" << endl;
#define yes  cout << "yes" << endl;
#define no   cout << "no" << endl;
#define pi pair<int, int>  
#define pll pair<ll,ll> 
#define vi vector<int>     
#define vll vector<ll>       
#define vpi vector<pi>        
#define vpll vector<pll>        
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>;
#define vvc vector<vector<char>>;
#define pqminI priority_queue<int,vector<int>,greater<int>>
#define pqmaxI priority_queue<int>
#define pqminLL priority_queue<ll,vector<ll>,greater<ll>>
#define pqmaxLL priority_queue<ll>
#define maxi(arr) *max_element(arr.begin(),arr.end())
#define mini(arr) *min_element(arr.begin(),arr.end())
#define all(arr) arr.begin(),arr.end()
const int mod  = 1e9 + 7;


// ================================= Imp Functions ======================================

vi sieve(int n)
{
    vi primes(n, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    return primes;
}

ll power(ll base ,ll ind){
    ll res = 1;
    base %= mod;
    while(ind > 0){
        if(base & 1){
            res = ((ll)res * base)%mod; 
        }
        base = ((ll)base * base)%mod;
        ind = ind >> 1;
    }
    return res;
}

ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r; // Since nCr(n, r) == nCr(n, n-r)

    ll result = 1;
    for (ll i = 0; i < r; ++i)
    {
        result *= (n - i);
        result /= (i + 1);
    }   
    return result;
}

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vi arr(n);
    read(arr);
    map<pll,ll>mp;
    ll ans = 0;
    for(int i =0 ;i<n;i++){
        pll curr = {arr[i] % x , arr[i] % y};
        ans += mp[{(x - curr.first)%x, curr.second}];
        mp[curr]++;
    }
    cout(ans);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}