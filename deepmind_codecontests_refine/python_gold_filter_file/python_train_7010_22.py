n, m = map(int, input().split())
if not n and m:
    print('Impossible')
else:
    print(n+m-min(m, n), m+n-1 if m else n)

