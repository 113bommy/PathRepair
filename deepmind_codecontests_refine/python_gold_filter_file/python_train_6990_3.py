R = lambda: map(int, input().split())

n, m = R()

t = None
cur = None
a = None
for i in range(n):
    a = tuple(R())
    s = list(set(a))
    if t is None and len(s) > 1:
        t = [(s[0], a.index(s[0])), a.index(s[1]), i]
    else:
        cur = a[0] if cur is None else cur^a[0]


if n == 1:
    ls = list(filter(lambda x: x[1], enumerate(a)))
    if ls:
        print('TAK')
        print(ls[0][0] + 1)
    else:
        print('NIE')
elif t:
    print('TAK')
    p1, p2, row = t
    col = p1[1] if p1[0]^cur else p2
    ls = [1]*row + [col+1] + [1]*(n-row-1)
    print(*ls, sep=' ')
elif cur:
    print('TAK')
    print(' '.join(['1']*n))
else:
    print('NIE')