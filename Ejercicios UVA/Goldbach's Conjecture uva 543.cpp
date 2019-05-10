#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll size;
vector<int> v;
bitset<10000000> primes;

//Sieve of eratosthenes
void sieve(ll m) 
{
   size=m+1;
   primes.set();
   primes[0]=primes[1]=0;
   for (ll i=2; i<=size;i++) 
   {
      if (primes[i]) 
	  {
		for (ll j=i*i;j<=size;j+=i) 
		{
		  primes[j]=0;
		}	
	  v.push_back((int)i);
      }
   }
}


bool isPrime(ll x) 
{
   if (x<=size) 
   {
      return primes[x];
   }
   for(int i=0; i<(int)v.size();i++) 
   {
      if (x%v[i]==0)
	  return false;
   }
   return true;
}

int main() 
{
   ll MM=1000000;
   ll m=sqrt(MM);
   sieve(m);

   int n;
   while(cin>>n&&n!=0) 
   {
      int i;
      for(i=0;i<n;i++) 
	  {
		if(isPrime(i) && isPrime(n-i)) 
		{
		    cout<<n<<" = "<<i<<" + "<<n - i<<endl;
		    break;
		}
      }
	  
	  if (i==n) 
	  {
		cout<<"Goldbach's conjecture is wrong"<<endl;
	  }
	}
  return 0;
}


