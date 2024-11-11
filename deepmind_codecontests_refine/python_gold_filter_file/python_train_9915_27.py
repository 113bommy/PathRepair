from itertools import accumulate

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [int(1e9+1)] + list(map(int, input().split())) + [int(1e9+1)]
    dp = list(accumulate(map(lambda x: 1 if x[1] > x[0] and x[1] > x[2] else 0,
              zip(a, a[1:], a[2:]))))
    t, l = (0, -1)
    for i in range(0, len(dp)-k+2):
        t, l = max((t, l), (dp[i+k-2] - dp[i], -(i+1)))
    print(' '.join(map(str, (t+1, -l))))
