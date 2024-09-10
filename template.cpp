#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

 #define trav(a,x) for (auto& a : x)
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(x) x.begin(), x.end()
#define ford(i, n) for (int i=0; i<(n); i++)
#define acc(a) accumulate(all(a), 0ll)
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
void precompute_factorials(ll n, ll m, vector<ll> &fact, vector<ll> &ifact) {   fact[0] = 1;   for (ll i = 1; i <= n; ++i) {fact[i] = fact[i - 1] * i % m;}ifact[n] = mminvprime(fact[n],m);   for (ll i = n - 1; i >= 0; --i) { ifact[i] = ifact[i + 1] * (i + 1) % m;}}
ll combination(ll n, ll r, ll m, vector<ll>&fact, vector<ll>&ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vl ip(int n){ vl v(n); trav(i,v) cin>>i;return v;}
vl prefix(vl &v){int n=v.size();vl ans(n);ans[0]=v[0];for(int i=1;i<n;i++) ans[i]=ans[i-1]+v[i];return ans;}
/*--------------------------------------------------------------------------------------------------------------------------*/
//int phi(int n){
// int result=n, x=sqrtl(n);
//for(int i=2;i< x;i++){
// if(n%i==0){
// while(n%i==0) n/=i;
//result-=result/i;
//}
// }
// if(n>1) result-=result/n;
//return result;
//}
//vi phi_1_to_n(int n){
//vi phi(n+1);
//for(int i=0;i<=n;i++) phi[i]=i;
//for(int i=2;i<=n;i++){
//if(phi[i]=i){
//for(int j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
//}
//}
// return phi;
//}
//****************************************************
//ll nCr(ll n , ll r) {
//if (r > n) return 0; if (r == 0 || n == r) return 1;
//r=min(n-r,r);int x=1;ll ans=1;
// while(r--){ ans=(ans*n)/x; n--; x++; }
//return ans;
// }
//****************************************************
vi tobinary(int n){
int i = 0; vi v(32,0);
while (n > 0) {
   v[i] = n % 2;n = n / 2; i++;
}
reverse(all(v));return v;
}
int todecimal(vi v){
 int ans=0;
for(int i=31;i>=0;i--){
 if(v[i]) ans+=pow(2,31-i);
} return ans;
}
//*****************************************
#define MAXN 1000002
vector<int> spf(MAXN + 1, 1);
void ss(){
spf[0] = 0;for (int i = 2; i <= MAXN; i++) {if (spf[i] == 1) { for (int j = i; j <= MAXN; j += i) { if (spf[j]== 1)spf[j] = i; } }}
}
//************************************************************





void solve(){

    
}

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t=1;
cin>>t;
while(t--)
{
solve();
}
return 0;
}
