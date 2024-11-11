n, m, *a = map(int, open(0).read().split())
a.sort()
print(sum(sorted([a[i + 1] - a[i] for i in range(m - 1)])[:max(0, m - n)]))