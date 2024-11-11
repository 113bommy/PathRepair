n, k = map(int, input().split())
x = list(map(int, input().split()))

m = min(b - a + min(abs(a), bas(b)) for a, b in zip(x, x[k-1]))
print(m)