[n, k] = map(int, input().split())
s = list(map(int, input().split()))
if sum(s) / n >= k:
    print(0)
else:
    print(2 * n * k - n - 2 * sum(s))
