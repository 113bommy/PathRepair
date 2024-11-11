n, M, *X = map(int, open(0).read().split())
print(max(0, min(X[1::2]) - max(X[::2]) + 1))
