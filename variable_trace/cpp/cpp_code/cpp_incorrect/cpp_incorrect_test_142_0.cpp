#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m, n;
    scanf("%d %d", &m, &n);
    int happyness[m][n];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> happyness[i][j];
      }
    }
    if (m == 1) {
      int min = happyness[0][0];
      for (int i = 1; i < n; ++i) {
        if (happyness[0][i] < min) min = happyness[0][i];
      }
      cout << min << endl;
    } else {
      int special_row = 0, ans1 = 0, ans2 = 0, k = 0, column1 = 0, column2 = 1;
      for (int i = 0; i < m; ++i) {
        int max, second_max, max_column, second_max_column;
        if (happyness[i][0] >= happyness[i][1]) {
          max = happyness[i][0], second_max = happyness[i][1];
          max_column = 0, second_max_column = 1;
        } else {
          second_max = happyness[i][0], max = happyness[i][1];
          max_column = 1, second_max_column = 0;
        }
        if (n > 2) {
          for (int j = 2; j < n; ++j) {
            if (happyness[i][j] > max) {
              second_max = max, max = happyness[i][j];
              second_max_column = max_column, max_column = j;
            } else if (happyness[i][j] > second_max && happyness[i][j] <= max) {
              second_max = happyness[i][j];
              second_max_column = j;
            }
          }
        }
        if (second_max > ans1) {
          ans1 = second_max, column1 = second_max_column, column2 = max_column;
        }
      }
      if (n > 2 && m > 1) {
        int columnmax[n - 2];
        for (int i = 0; i < n; ++i) {
          if (i != column1 && i != column2) {
            int j = 0;
            columnmax[k] = happyness[i][j];
            for (j = 1; j < m; ++j) {
              if (happyness[j][i] > columnmax[k]) {
                columnmax[k] = happyness[j][i];
              }
            }
            ++k;
          }
        }
        ans2 = columnmax[0];
        for (int i = 0; i < n - 2; ++i) {
          if (columnmax[i] < ans2) ans2 = columnmax[i];
        }
        if (ans2 <= ans1)
          cout << ans2 << endl;
        else
          cout << ans1 << endl;
      } else
        cout << ans1 << endl;
    }
  }
  return 0;
}
