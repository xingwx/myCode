#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "B-large-practice"

int L,N,C,a[1000005];

typedef long long ll;

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int T;
	cin>>T;
	REP(t,T){
		ll t2;
		cin>>L>>t2>>N>>C;
		REP(i,C){cin>>a[i];}
		REP(i,N){
			a[i]=a[i%C];
		}
		ll sum2=0;
		REP(i,N)sum2+=a[i]*2;
		ll sum=0;
		int p;
		for(p=0;p<N&&sum<t2/2;p++)sum+=a[p];
		a[N]=sum-t2/2;
		sort(a+p,a+N+1,greater<int>());
		REP(i,L)if(p+i<=N)sum2-=a[p+i];
		printf("Case #%d: %lld\n",t+1, sum2);
		cerr<<t+1<<endl;
	}
}
