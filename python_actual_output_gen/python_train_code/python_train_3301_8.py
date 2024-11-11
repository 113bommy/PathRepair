n, T, *t = map(int, open(0).read().split())
print(sum(min(t[i+1] - t[i], T) for i in range(n)))