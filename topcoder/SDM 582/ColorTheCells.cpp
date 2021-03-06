#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define PI 3.14159265359
#define REP(i,n) for(LL i=0;i<(n);++i)
#define FOR(i,k,n) for (LL i=(k); i<=(LL)(n); ++i)
#define X first
#define Y second
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;

class ColorTheCells {
public:
	int minimalTime(vector <int>);
	int n;
	vector<int> dry;
	int time(int list[],int lev){
		if(lev==0){
		vector<int> v;
		REP(i,n)v.PB(list[i])
		return time2(v);
		}
		int t=1e9;
	}
	
	int time2(vector<int> v){
		int pos=0,num=0,t=0;
		while(num!=7){
			if(pos<list[num]){
				t+=list[num]-1-pos;
				pos=
			}
		
		}
	}
};

int ColorTheCells::minimalTime(vector <int> dryingTime) {
	dry=dryingTime;
	int  list[]={0,1,2,3,4,5,6};
	int m=1e9;
	int num=1;
	n=dry.size();
	REP(i,dry.size())num*=(i+1);
	REP(i,num){
		m=min(m,time(list,dry.size()));
		next_permutation(list,list+7);	
	}
	return m;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	ColorTheCells *obj;
	int answer;
	obj = new ColorTheCells();
	clock_t startTime = clock();
	answer = obj->minimalTime(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {2,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,2,100,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {33,58,21,44};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 26;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {35198,26281,72533,91031,44326,43178,85530};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 26287;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// There are N cells in a row.
// The cells are numbered 0 through N-1 from left to right.
// Magical Girl Riena wants to give magical powers to all the cells by painting all of them using magic colors.
// Riena starts at time 0 in cell 0.
// She can do three types of actions:
// 
// She can wait in her current cell for as long as she wants.
// She may move to an adjacent cell. The move takes 1 unit of time.
// She may paint an adjacent cell. Painting the cell takes 1 unit of time. (Note that she cannot paint the cell she currently stands in, only the adjacent ones.)
// 
// There is one additional restriction: Riena cannot enter a freshly painted cell until the paint dries.
// You are given a vector <int> dryingTime with N elements.
// For each i, dryingTime[i] is the time needed for the paint in the cell i to dry after Riena finished painting the cell.
// Once cell i has already been painted, Riena is not allowed to start moving to cell i before the paint in cell i gets dry.
// 
// For example, suppose that Riena is currently in cell 3 and we have dryingTime[2]=7.
// At time 12 Riena starts painting the adjacent cell 2.
// She will finish painting the cell at time 12+1 = 13.
// The paint in the cell will be dry at time 13+7 = 20.
// Therefore, the earliest time Riena can be in cell 2 again is 21.
// (At time 20 she can start moving from cell 3 to cell 2, and the move takes 1 unit of time.)
// 
// Riena wants to paint all N cells, and she wants to finish painting as quickly as possible.
// She may paint the cells in any order she likes.
// Compute and return the earliest possible time when Riena can finish painting the last cell.
// (Note that the return value you are trying to minimize is the moment when Riena finishes painting, not the moment when the paint dries.)
// 
// DEFINITION
// Class:ColorTheCells
// Method:minimalTime
// Parameters:vector <int>
// Returns:int
// Method signature:int minimalTime(vector <int> dryingTime)
// 
// 
// CONSTRAINTS
// -dryingTime will contain between 2 and 7 elements, inclusive.
// -Each element of dryingTime will be between 1 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2, 2, 3}
// 
// Returns: 6
// 
// One of the optimal solutions:
// 
// At time 0, Riena starts moving from cell 0 to cell 1.
// At time 1, she reaches cell 1 and starts painting cell 0.
// At time 2, she finishes painting cell 0 and starts painting cell 2. The paint in cell 0 starts drying.
// At time 3, Riena finishes painting cell 2. The paint in cell 2 starts drying. Riena now has to wait because she already painted both adjacent cells and she cannot move to either of them yet.
// At time 4, cell 0 becomes dry and Riena starts moving from cell 1 to cell 0.
// At time 5, Riena reaches cell 0 and starts painting cell 1.
// At time 6, Riena finishes painting cell 1 and she is done. (Also, cell 2 is now dry and cell 1 will be dry at time 8, but we don't care about them any more.)
// 
// 
// 1)
// {1, 2, 100, 1}
// 
// Returns: 7
// 
// 
// 
// 2)
// {33, 58, 21, 44}
// 
// Returns: 26
// 
// 
// 
// 3)
// {35198, 26281, 72533, 91031, 44326, 43178, 85530}
// 
// Returns: 26287
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
