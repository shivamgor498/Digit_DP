//shivamgor498
//   https://codeforces.com/contest/628/problem/D
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
#define MAXL 100005
using namespace std;
vector<ll>prime(15000002,0);
ll mM(ll a,ll b,ll mod){ll res = 0;a %= mod;while(b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=(res*x)%p;res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=(x*x)%p;if(x<0)x=(x+p)%p;x%=p;}return res;}
ll inv(ll n){return fpow(n,hell-2,hell);}
ll modmul(ll x,ll y){return ((x%hell)*(y%hell))%hell;}
ll modadd(ll x,ll y){ll temp=x%hell+y%hell;temp%=hell;if(temp<0)temp = (temp+hell)%hell;return temp;}
void sieve(){
	prime[1] = 1;
	for(ll i=2;i<=15000000;i++)
		if(!prime[i])
			for(ll j=i;j<=15000000;j+=i)
				if(!prime[j])
					prime[j] = i;
}
ll dp[2005][2005][2][2];
ll m,d;
vector<ll>num;
ll fun(ll ind,ll sum,ll rest,ll ok)
{
	if(ind==num.size())
	{
		if(ok && !sum)
			return 1;
		return 0;	
	}
	if(dp[ind][sum][rest][ok]==-1)
	{
		ll limit;
		ll ans = 0;
		if(rest)
			limit = num[ind];
		else
			limit = 9;
		for(int i=0;i<=limit;i++)
		{
			ll nrest = rest;
			ll nok = ok;
			if(rest && i<limit)
				nrest = 0;
			if(ind%2 && i!=d)
				nok = 0;
			if(ind%2==0 && i==d)
				nok = 0;
			if(nok)
				ans = modadd(ans,fun(ind+1,(10*sum + i)%m,nrest,nok));
		}
		dp[ind][sum][rest][ok] = ans;
	}
	return dp[ind][sum][rest][ok];
}
ll check(string s)
{
	bool ok = true;
	ll sum = 0;
	for(int i=0;i<s.size();i++)
	{
		if(i%2 && (s[i]-'0')!=d)
			ok = false;
		else if(i%2==0 && (s[i]-'0')==d)
			ok = false;
		sum = (sum*10 + s[i] - '0')%m;
	}
	if(ok && !sum)
		return 1;
	return 0;
}
ll solve(string s)
{
	num.clear();
	for(int i=0;i<s.size();i++)
		num.pb(s[i]-'0');
	for(int i=0;i<2005;i++)
		for(int j=0;j<2005;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					dp[i][j][k][l] = -1;
	return fun(0,0,1,1);
}
int main(){
    ll t = 1;
   	//cin >> t;
    while(t--)
    {
    	string a,b;
    	cin >> m >> d >> a >> b;
    	//cout << solve(b) << "\n";
    	cout << modadd(modadd(solve(b),-solve(a)),check(a)) << "\n";
    }
}
