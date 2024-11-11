import itertools


n, m, d = map(int, input().split())
a = []
for _ in range(n):
    a += list(map(int, input().split()))
# print(a)
a = list((a[i] - a[0]) for i in range(n * m))
# print(a)
if any([a[i] % d != 0 for i in range(n * m)]):
    print(-1)
else:
    ps = list(itertools.accumulate(a))
    ans = [(a[i] * (i + 1) - ps[i] + (ps[n * m - 1] - ps[i]) - a[i] * (n * m - i - 1)) // d for i in range(n * m)]
    # print(ps)
    print(min(ans))
