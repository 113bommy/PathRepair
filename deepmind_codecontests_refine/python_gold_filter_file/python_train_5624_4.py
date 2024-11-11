# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def leven(s1, s2):
    n1 = len(s1)
    n2 = len(s2)
    dp = [[0]*(n1+1) for _ in range(n2+1)]

    for i in range(1, n1+1):
        dp[0][i] = i
    for i in range(1, n2+1):
        dp[i][0] = i

    for j in range(1, n2+1):
        for k in range(1, n1+1):
            m = min(dp[j-1][k], dp[j][k-1])+1
            if s1[k-1] == s2[j-1]:  # 最後の文字削除
                m = min(m, dp[j-1][k-1])
            else:
                m = min(m, dp[j-1][k-1]+1)
            dp[j][k] = m
    print(dp[-1][-1])


s1 = input()[:-1]
s2 = input()[:-1]
leven(s1, s2)

