#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;
unordered_map<int, vector<pii> > left;
int found[1000], a[1000];

int main(){
	// freopen("test.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int total;
	// Algo Credit to UtopiaBeam; I am so bad w/ algo now
	for (int i=0; i<m; i++){ // O(NM)
		scanf("%d", &total);
		for (int j=0; j<n; j++){
			left[total-a[j]].push_back(pii(i, j)); // questionID, usedNumberIndex
			// left[sum2] = [(questionID, uedNumberIndex), ...]
			// it means that if sum of 2 numbers is sum2 -> it could potentially solve question #qID 
			// if a[usedNumberIndex] isn't used twice 
		}
	}
	/* If we use map as number of occurence of a[i] (to handle duplicate)
		then for each quesion (M total) we need to loop N^2 times to answer each 
		: O(M * N^2 * log(N)) --> Timeout (N, M <= 1000; the PDF states it wrong)


		Using this method we loop more in first phase to calculate solvable pair sum (totalSum[i] - a[i])
		but the loop after is faster; we only loop once (through O(N^2) possible pairs); and looped through the vector<pair<int,int> >
		: O(N^2 * log(NM) * ...) -->  OK
		*/
	int qID, idx;
	for (int i=0; i<n; i++) // O(N^2 * logNM * ...)
		for (int j=i+1; j<n; j++){
			if (left.find(a[i] + a[j]) != left.end()){ // possible
				for (pii x: left[a[i] + a[j]]){
					qID = x.first, idx = x.second;
					if (idx != i && idx != j){
						found[qID] = 1;
						break;
					}
				}
			}
		}
	for (int i=0; i<m; i++)
		printf("%s\n", found[i]?"YES":"NO");
	return 0;
}