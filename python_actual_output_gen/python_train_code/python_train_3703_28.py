x, xn = 0, 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    if a < 0:
        xn += 1
    else:
        x += 1
if min(x, xn) == 1:
    print('YES')
else:
    print('NO')
    