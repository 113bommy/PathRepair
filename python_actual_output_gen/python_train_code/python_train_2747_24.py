from sys import stdin
n, m, *x = map(int, stdin.read().split())
x.sort()
y = [x[i] - x[i - 1] for i in range(1, m)]
y.sort()
print(sum(y[:-n + 1]) if n < m else 0)
