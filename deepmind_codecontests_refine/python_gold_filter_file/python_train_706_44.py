import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    md = 10 ** 9 + 7
    n, k = map(int, input().split())
    aa = list(map(int, input().split()))
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(n):
        a = aa[i]
        s = 0
        for j in range(k + 1):
            s += dp[i][j]
            if j - a - 1 >= 0: s -= dp[i][j - a - 1]
            s %= md
            dp[i + 1][j] = s
    # p2D(dp)
    print(dp[n][k])

main()
