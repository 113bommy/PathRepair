costs = [2, 5, 5, 4, 5, 6, 3, 7, 6]


def main():
    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    dp = [-1 for _ in range(N + 1)]
    dp[0] = 0
    for i in range(1, N + 1):
        for a in A:
            if i < costs[a - 1]:
                continue
            dp[i] = max(dp[i], dp[i - costs[a - 1]] * 10 + a)
    print(dp)


main()
