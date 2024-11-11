# dp[c1][c2][c3]=
# 		(1個の皿がc1枚、2個の皿がc2枚、3個の皿がc3枚あるとき、全て食べるまでの操作回数の期待値)

N = int(input())
A = list(map(int, input().split()))
cnt1 = A.count(1)
cnt2 = A.count(2)
cnt3 = A.count(3)

dp = [[[-1] * (N + 1) for _ in range(N + 1)] for _ in range(N + 1)]
dp[0][0][0] = 0

# dp[c1][c2][c3]=
# 	1
# 	+dp[c1−1][c2][c3]∗(1個の皿が選ばれる確率)
# 	+dp[c1+1][c2−1][c3]∗(2個の皿が選ばれる確率)
# 	+dp[c1][c2+1][c3−1]∗(3個の皿が選ばれる確率)
# 	+dp[c1][c2][c3]∗(0個の皿が選ばれる確率)
# ↓式変形↓
# dp[c1][c2][c3]=
# 	1/(1−(0個の皿が選ばれる確率))
# 	+ dp[c1−1][c2][c3]*(1個の皿が選ばれる確率)/(1−(0個の皿が選ばれる確率))
# 	+ dp[c1+1][c2−1][c3]*(2個の皿が選ばれる確率)/(1−(0個の皿が選ばれる確率))
# 	+ dp[c1][c2+1][c3−1]*(3個の皿が選ばれる確率)/(1−(0個の皿が選ばれる確率))


def func(c1, c2, c3):
    if dp[c1][c2][c3] != -1:
        return dp[c1][c2][c3]

    #　1-(0個の皿が選ばれる確率), 繰り返し登場するので先に計算しておく
    prob = 1 - (N - c1 - c2 - c3) / N

    temp = 1 / prob
    if c1 > 0:
        temp += func(c1 - 1, c2, c3) * (c1 / N) / prob
    if c2 > 0:
        temp += func(c1 + 1, c2 - 1, c3) * (c2 / N) / prob
    if c3 > 0:
        temp += func(c1, c2 + 1, c3 - 1) * (c3 / N) / prob

    dp[c1][c2][c3] = temp
    return temp


print(func(cnt1, cnt2, cnt3))
