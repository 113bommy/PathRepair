n, d = [int(cord) for cord in input().split(' ')]
motherfuckers = int(input())
for i in range(motherfuckers):
    x, y = [int(cord) for cord in input().split(' ')]
    if (y <= x + d) and (y >= x * (-1) + d) and (y >= x - d) and (y <= x * (-1) + d + (n-d) * 2):
        print('YES')
    else: print('NO')
