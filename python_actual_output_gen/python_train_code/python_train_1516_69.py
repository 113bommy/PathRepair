x = list(map(int, input().split()))
if abs(x[0] - x[1]) * x[3] < abs(x[0] - x[2]) * x[4] + 2 * x[5] + abs(x[0] - x[1]) * x[4]:
    print('NO')
else:
    print('YES')
