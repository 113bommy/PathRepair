x, xn = 0, 0
for _ in range(int(input())):
    x, y = map(int, input().split())
    if x < 0:
        xn += 1
    else:
        x += 1
if min(x, xn) <= 1:
    print('YES')
else:
    print('NO')
    