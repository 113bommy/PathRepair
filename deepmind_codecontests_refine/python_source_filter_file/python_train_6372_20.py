#
# Created by Polusummator on 21.05.2020
# --------- Little PyPy Squad ---------
# Verdict: 1.MLE 2.TLE
#
n, k = [int(i) for i in input().split()]
s = input() + '#'
al = [i for i in input().split()]
# dp = [[0] * len(s) for i in range(len(s))]
ans = 0
# dp = [0] * len(s)
cur = 0
for i in range(n + 1):
    if s[i] in al:
        cur += 1
    else:
        # print(cur)
        ans += ((cur + 1) // 2) * cur
        cur = 0
# --- Work, but TLE ---
# new_dp = []
# while len(dp) > 1:
#     for i in range(1, len(dp)):
#         if dp[i - 1] + dp[i] == 2:
#             new_dp.append(1)
#             ans += 1
#         else:
#             new_dp.append(0)
#     dp = new_dp
#     new_dp = []
# --- Work, but MLE ---
# for i in range(n):
#     if s[i] in al:
#         dp[i][i] = 1
#         ans += 1
# for f in range(1, n):
#     for i in range(n - f):
#         j = i + f
#         if (dp[i + 1][j] + dp[i][j - 1]) == 2:
#             dp[i][j] = 1
#             ans += 1
print(ans)
# for i in dp:
#     print(*i)
