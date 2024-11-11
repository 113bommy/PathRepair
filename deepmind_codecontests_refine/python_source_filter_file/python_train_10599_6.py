import math
MOD = int(1e9+7)


def main():
    N, K = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(N)]
    x = int(math.log2(K))
    dp = [[[0] * N for _ in range(N)] for _ in range(x+1)]
    dp[0] = A
    for d in range(x):
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    dp[d+1][i][j] = (dp[d+1][i][j] +
                                     dp[d][i][k] * dp[d][k][j]) % MOD
    ans = [1] * N
    for d in range(x+1):
        if K & (2 ** d) == 0:
            continue
        prev = list(ans)
        ans = [0] * N
        for i in range(N):
            for j in range(N):
                ans[j] = (ans[j] + dp[d][i][j] * prev[i]) % MOD

    print(sum(ans) % MOD)


if __name__ == "__main__":
    main()
