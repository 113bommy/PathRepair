n, k = map(int, input().split())
if n < k or k > 26: print(-1)
elif k == 1: print('a' if n == 1 else -1)
else: print(('ab' * (n // 2))[: n - k + 2] + 'cdefghijklmnopqrstuvwxyz'[: k - 2])