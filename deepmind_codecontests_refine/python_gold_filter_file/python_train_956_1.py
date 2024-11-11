n, m, d = list(map(int, input().strip().split(' ')))
c = list(map(int, input().strip().split(' ')))


res = []
for i, ci in enumerate(c):
    empty = n - len(res) - sum(c[i:])
    if empty >= d - 1:
        res.extend(['0']*(d - 1))
    else:
        res.extend(['0'] * empty)
    res.extend([str(i + 1) for _ in range(ci)])

if n - len(res) < d:
    res.extend(['0'] * (n - len(res)))
    print("YES")
    print(' '.join(res))
else:
    print("NO")