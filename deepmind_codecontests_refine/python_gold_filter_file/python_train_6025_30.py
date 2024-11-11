N, L, *a = map(int, open(0).read().split())
for i, (n, m) in enumerate(zip(a, a[1:]), 1):
    if n + m >= L:
        print('Possible')
        print('\n'.join(c for it in (range(1,i), range(N-1,i,-1), [i]) for c in map(str, it)))
        break
else:
    print('Impossible')