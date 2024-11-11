from math import ceil
t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    a.sort()
    s = 0
    d = n - ceil(n / 2) + 1
    f = n - d
    for j in range(k):
        s += a[f]
        f -= d
    print(s)