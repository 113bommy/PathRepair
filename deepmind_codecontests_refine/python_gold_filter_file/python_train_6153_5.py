n, d = map(int, input().split())

m = int(input())

for i in range(m):
    x, y = map(int, input().split())

    f1 = x + d
    f2 = -x + n + (n - d)
    f3 = x - d
    f4 = -x + d

    if y <= min(f1, f2) and y >= max(f3, f4):
        print('YES')
    else:
        print('NO')