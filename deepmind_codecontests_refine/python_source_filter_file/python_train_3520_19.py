INF = 10**12


def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    dp = [[INF]*(N+1) for _ in range(N)]
    cost = [[INF]*(N+1) for _ in range(N)]

    for i in range(N):
        dp[i][i+1] = A[i]
        cost[i][i+1] = 0

    for w in range(2, N+1):
        for le in range(N-w+1):
            ri = le + w
            for i in range(le+1, ri):
                if dp[le][ri] >= dp[le][i] + dp[i][ri]:
                    dp[le][ri] = dp[le][i] + dp[i][ri]
                    cost[le][ri] = min(cost[le][ri],
                                       cost[le][i] + cost[i][ri] + dp[le][ri])

    print(cost[0][N])


if __name__ == '__main__':
    main()
