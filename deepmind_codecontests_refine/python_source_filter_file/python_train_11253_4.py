from math import sqrt

n = int(input())

step = int(sqrt(n))
assert step**2 <= n and (step + 1)**2 > n
ans = []
for start in range(0, n, step):
    ans.extend(range(start, start + step)[::-1])
print(' '.join(str(v + 1) for v in ans))