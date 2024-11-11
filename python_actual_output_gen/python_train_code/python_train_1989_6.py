n, m = map(int, input().split())

a = [list(map(int, input().split())) for _ in range(n)]
b = [list(map(int, input().split())) for _ in range(n)]

order = lambda x, y: (min(x, y), max(x, y))

for r in range(n):
    for c in range(m):
        mi, mx = order(a[r][c], b[r][c])
        a[r][c], b[r][c] = mi, mx



def ok(w):
    for r in range(n):
        for c in range(m - 1):
            if w[r][c] >= w[r][c + 1]: return False
    for c in range(m):
        for r in range(r - 1):
            if w[r][c] >= w[r + 1][c]: return False
    return True


if ok(a) and ok(b):
    print('Possible')
else:
    print('Impossible')
