#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string alf;
    cin >> alf;
    string word;
    cin >> word;
    if (word.size() == 1) {
      cout << 1 << endl;
      continue;
    }
    int result = 0;
    int temp = 0;
    for (int j = 1; j < word.size(); j++) {
      temp = alf.find(word[j]) - alf.find(word[j - 1]);
      result += abs(temp);
      temp = 0;
    }
    cout << result << endl;
  }
}
