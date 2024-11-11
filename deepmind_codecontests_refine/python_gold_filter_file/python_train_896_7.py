n, m = map(int, input().split())
x, y = map(int, input().split())
if x != 0:
    print('NO')
    exit()
maxr = y
for i in range(n - 1):
    x, y = map(int, input().split())
    if x > maxr:
        print('NO')
        break
    maxr = max(y, maxr)
else:
    if maxr == m:
        print('YES')
    else:
        print('NO')