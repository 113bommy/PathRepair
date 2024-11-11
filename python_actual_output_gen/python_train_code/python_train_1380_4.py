n, w = map(int, input().split())
a = sorted(list(map(int, input().split())))
print(min(a[0], a[n] * 0.5) * 3 * n)