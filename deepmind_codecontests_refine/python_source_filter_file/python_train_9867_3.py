import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    A, B, C, D = [int(x) for x in input().split()]

    MOD = 998244353

    dp = [[0] * (D - B + 1) for j in range(C - A + 1)]

    for j in range(C - A + 1):
        if j == 0:
            dp[j][0] = 1
        else:
            dp[j][0] = B ** j % MOD
        for i in range(1, D - B + 1):
            if j == 0:
                dp[j][i] = dp[j][i - 1] * (A + j) % MOD
            else:
                dp[j][i] = (dp[j][i - 1] * (A + j) + (B + i) * dp[j - 1][i] - dp[j - 1][i - 1] * (
                            (A + j - 1) * (B + i - 1))) % MOD

    print(dp[-1][-1] % MOD)


if __name__ == '__main__':
    main()
