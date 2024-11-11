n, m = map(int, input().split())
if not n:
    print('Impossible')
else:
    print(n+m-min(m, n), m+n-1 if m else n)

