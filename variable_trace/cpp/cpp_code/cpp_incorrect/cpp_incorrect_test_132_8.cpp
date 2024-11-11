#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  int A[7];
  while (t--) {
    for (int i = 0; i < 7; i++) cin >> A[i];
    vector<int> ans(3);
    ans.push_back(A[0]);
    ans.push_back(A[1]);
    if (A[0] + A[1] > A[2])
      ans.push_back(A[2]);
    else
      ans.push_back(A[3]);
    for (int vals : ans) cout << vals << " ";
    puts("");
  }
  return 0;
}
