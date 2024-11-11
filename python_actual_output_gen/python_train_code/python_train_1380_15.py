import sys

[n, w], a = map(int, input().split()), sorted(map(int, input().split()))
print(min(w / 3, a[n] / 2, a[0]) * 3 * n)
