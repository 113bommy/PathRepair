#include <bits/stdc++.h>
using namespace std;
vector<int> vi[1000005];
vector<int>::iterator child;
vector<int> vi2[1000005];
vector<int> vi3[1000005];
vector<long long int> vl;
vector<vector<pair<int, int> > > vii;
vector<pair<long long int, long long int> > vll;
int arr[1000005];
int arr2[1000005];
bool check[1000005];
bool check2[1000][1000];
int n, m;
vector<char> vec[1000005];
int main() {
  int test = 1;
  for (int xx = 1; xx <= test; xx++) {
    scanf("%d", &n);
    scanf("%d", &m);
    char aa;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> aa;
        vec[i].push_back(aa);
        ;
      }
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < m; j++) {
        if (vec[i][j - 1] == 'X' && vec[i - 1][j] == 'X') {
          arr[j + 1]++;
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      arr[i] += arr[i - 1];
    }
    int k;
    scanf("%d", &k);
    int a, b;
    for (int i = 0; i < k; i++) {
      scanf("%d", &a);
      scanf("%d", &b);
      int ans = arr[b] - arr[a - 1];
      if (ans && a < b) {
        printf("NO\n");
      } else
        printf("YES\n");
    }
  }
}
