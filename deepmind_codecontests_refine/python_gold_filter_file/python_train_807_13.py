import sys
sys.setrecursionlimit(2000 * 2)
n = int(input())
a = list(map(int, input().split()))
a = [(i, v) for i, v in enumerate(a)]
a.sort(key=lambda x: x[1], reverse=True)

dp = [[-1] * (m + 1) for m in range(n + 1)]
# m: 何人選んだか, l: 左を選んだ人数
def f(m, l):
    if m == n: return 0
    if dp[m][l] != -1: return dp[m][l]
    r = n - m + l - 1
    i, v = a[m]
    if i >= l: dp[m + 1][l + 1] = f(m + 1, l + 1)
    if i <= r: dp[m + 1][l] = f(m + 1, l)
    return max(dp[m + 1][l + 1] + v * (i - l), dp[m + 1][l] + v * (r - i))
print(f(0, 0))