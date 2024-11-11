n, k, s = map(int, input().split())
print([s] * k + [1 if s == 10 ** 9 else s + 1] * (n - k))
