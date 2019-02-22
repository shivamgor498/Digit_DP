//shivamgor498
//   https://vjudge.net/problem/LightOJ-1205
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
using namespace std;
/*vector<ll>prime(15000002,0);
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
}*/
vector<ll>num,temp(40,-1);
ll dp[40][40][2]; // length,pos,valid
ll fun(ll sz,ll pos,ll isStart,ll rest,bool valid)
{
	/*cout << sz << " " << pos << " " << isStart << " " << rest << " " << ans << "\n";
	for(int i=0;i<sz;i++)
		cout << temp[i];
	cout << "\n";*/
	if(pos>=sz || sz<1)
		return valid;
	ll tans = 0;
	if(!rest && dp[sz][pos][valid]!=-1)
		return dp[sz][pos][valid];
	ll limit;
	if(rest)
		limit = num[pos];
	else
		limit = 9;
	for(int i=0;i<=limit;i++)
	{
		temp[pos] = i;
		if(isStart && i==0)
			tans+=fun(sz-1,pos,isStart,rest&&(i==limit),valid);
		else if(valid && pos>=(sz/2))
			tans+=fun(sz,pos+1,0,rest&&(i==limit),temp[sz-pos-1]==i);
		else
			tans+=fun(sz,pos+1,0,rest&&(i==limit),valid);
	}
	if(!rest)
		dp[sz][pos][valid] = tans;
	return tans;
}
ll solve(ll n)
{
	if(n<10)
		return n+1;
	for(int i=0;i<40;i++)
		temp[i] = -1;
	for(int i=0;i<40;i++)
		for(int j=0;j<40;j++)
			for(int k=0;k<2;k++)
				dp[i][j][k] = -1;
	num.clear();
	while(n)
	{
		num.pb(n%10);
		n/=10;
	}
	reverse(num.begin(),num.end());
	return fun(num.size(),0,1,1,1); // length,pos,isstart,limit,ans
}
int main(){
	ios
    ll t = 1;
   	cin >> t;
   	ll cnt = 0;
    while(t--)
    {
    	ll a,b;
    	cin >> a >> b;
    	if(a>b)
    		swap(a,b);
    	//cout << solve(a) << "\n";
    	cout << "Case " << ++cnt << ": ";
 		cout << solve(b) - solve(a-1) << "\n";   	
    }
}
