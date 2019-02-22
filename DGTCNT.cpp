//shivamgor498
//https://www.codechef.com/problems/DGTCNT
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
#define MAXL 100005
#define pll pair<ll,ll>
#define L 1000000000
using namespace std;
//vector<ll>prime(15000002,0);
ll mM(ll a,ll b,ll mod){ll res = 0;a %= mod;while(b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=(res*x)%p;res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=(x*x)%p;if(x<0)x=(x+p)%p;x%=p;}return res;}
ll inv(ll n,ll p){return fpow(n,p-2,p);}
ll modmul(ll x,ll y){return (x*y)%hell;}
ll modadd(ll x,ll y){if(x>=hell)x-=hell;if(y>=hell)y-=hell;ll temp=x+y;if(temp>=hell)temp-=hell;if(temp<0)temp = temp+hell;return temp;}
/*void sieve(){
	prime[0] = -1;
	prime[1] = 0;
	for(ll i=2;i<=15000000;i++)
		if(!prime[i])
			for(ll j=i;j<=15000000;j+=i)
				if(!prime[j])
					prime[j] = i;
}*/
int main(){
	ios
	ll t = 1;
	cin >> t;
	while(t--){
		
	}
}
