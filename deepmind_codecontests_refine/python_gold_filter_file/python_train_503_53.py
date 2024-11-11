import sys
input = sys.stdin.readline


def main():
    N, A = map(int, input().split())
    X = list(map(int, input().split()))

    M = max(max(X), A)*N
    dp = [[[0 for k in range(M+1)] for j in range(N+1)] for i in range(N+1)]
    dp[0][0][0] = 1
    for i in range(N):
        for j in range(N):
            for k in range(M):
                if dp[i][j][k]:
                    dp[i+1][j][k] += dp[i][j][k]
                    dp[i+1][j+1][k+X[i]] += dp[i][j][k]
    ans = 0
    for j in range(1, N+1):
        ans += dp[N][j][A*j]
    print(ans)


if __name__ == '__main__':
    main()
