/*

A1. Special Task


time limit per test:
1 second

memory limit per test:
256 megabytes

input:
standard input

output:
standard output

Special Agent Smart Beaver works in a secret research department of ABBYY. He's been working there for a long time and is satisfied with his job, as it allows him to eat out in the best restaurants and order the most expensive and exotic wood types there.

The content special agent has got an important task: to get the latest research by British scientists on the English Language. These developments are encoded and stored in a large safe. The Beaver's teeth are strong enough, so the authorities assured that upon arriving at the place the beaver won't have any problems with opening the safe.

And he finishes his aspen sprig and leaves for this important task. Of course, the Beaver arrived at the location without any problems, but alas. He can't open the safe with his strong and big teeth. At this point, the Smart Beaver get a call from the headquarters and learns that opening the safe with the teeth is not necessary, as a reliable source has sent the following information: the safe code consists of digits and has no leading zeroes. There also is a special hint, which can be used to open the safe. The hint is string s with the following structure:

• if si = "?", then the digit that goes i-th in the safe code can be anything (between 0 to 9, inclusively);
• if si is a digit (between 0 to 9, inclusively), then it means that there is digit si on position i in code;
• if the string contains letters from "A" to "J", then all positions with the same letters must contain the same digits and the positions with distinct letters must contain distinct digits.
• The length of the safe code coincides with the length of the hint.


For example, hint "?JGJ9" has such matching safe code variants: "51919", "55959", "12329", "93539" and so on, and has wrong variants such as: "56669", "00111", "03539" and "13666".

After receiving such information, the authorities change the plan and ask the special agents to work quietly and gently and not to try to open the safe by mechanical means, and try to find the password using the given hint.

At a special agent school the Smart Beaver was the fastest in his platoon finding codes for such safes, but now he is not in that shape: the years take their toll ... Help him to determine the number of possible variants of the code to the safe, matching the given hint. After receiving this information, and knowing his own speed of entering codes, the Smart Beaver will be able to determine whether he will have time for tonight's show "Beavers are on the trail" on his favorite TV channel, or he should work for a sleepless night...


Input

The first line contains string s — the hint to the safe code. String s consists of the following characters: ?, 0-9, A-J. It is guaranteed that the first character of string s doesn't equal to character 0.

The input limits for scoring 30 points are (subproblem A1):
•1 ≤ |s| ≤ 5.


The input limits for scoring 100 points are (subproblems A1+A2):
•1 ≤ |s| ≤ 105.


Here |s| means the length of string s.


Output

Print the number of codes that match the given hint.


Sample test(s)



Input
AJ



Output
81



Input
1?AA



Output
100

 */

#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <cmath>
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
#define REP(i,n) for(LL i=0;i<(n);++i)
#define FOR(i,k,n) for (LL i=(k); i<=(LL)(n); ++i)
#define X first
#define Y second
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
typedef pair<int, int> PII;
typedef vector<int> VI;

//#define OPENFILE
#define FILENAME "small"

#define MX 110

typedef long long LL;
typedef long double LD;

VI ans;
set<char> s;
int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	cout.precision(15);
	char c;
	c = getchar();
	if (c >= '0' && c <= '9') {
		ans.PB(1);
	} else if (c == '?') {
		ans.PB(9);
	} else if (c >= 'A' && c <= 'J') {
		s.insert(c);
		ans.PB(9);
	}
	while ((c = getchar()) != '\n') {
		if (c >= '0' && c <= '9') {
			;
		} else if (c == '?') {
			int add = 0;
			for (int i = 0; i < ans.size(); i++) {
				int temp = ans[i] * 10 + add;
				ans[i] = temp % 10;
				if (temp >= 10)
					add = temp / 10;
				else
					add = 0;
			}
			if (add != 0)
				ans.PB(add);
		} else if (c >= 'A' && c <= 'J') {
			if (s.count(c) == 0) {

				int add = 0;
				for (int i = 0; i < ans.size(); i++) {
					int temp = ans[i] * (10-s.size()) + add;
					ans[i] = temp % 10;
					if (temp >= 10)
						add = temp / 10;
					else
						add = 0;
				}
				if (add != 0)
					ans.PB(add);
				s.insert(c);

			}
		}

	}
	REP(i,ans.size()){
		cout<<ans[ans.size()-i-1];
	}
	cout<<endl;
}