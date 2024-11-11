N = int(input())
A = [int(_) for _ in input().split()]
B = [int(_) for _ in input().split()]


def count(n, a, b):
    a0, a1, a2 = a
    b0, b1, b2 = b
    dp = [0] * (n + 1)
    for i in range(n + 1):
        c0 = dp[i - a0] + b0 if i - a0 >= 0 else 0
        c1 = dp[i - a1] + b1 if i - a1 >= 0 else 0
        c2 = dp[i - a2] + b2 if i - a2 >= 0 else 0
        dp[i] = max([i, c0, c1, c2])
    return dp[n]


print(count(count(N, A, B), B, A))
