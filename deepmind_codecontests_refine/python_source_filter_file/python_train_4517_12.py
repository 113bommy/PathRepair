ss = lambda: input()
si = lambda: int(input())

n, k = map(int, ss().split())

s = list(range(1, n + 1))

print(s[:n - k - 1] + list(reversed(s[n - k - 1:])))
