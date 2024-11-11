def solve():
    a = list(input())
    dem_E = 0
    dem_N = 0
    for i in a:
        if i == 'E':
            dem_E += 1
        else:
            dem_N += 1
    if dem_E == 1 and dem_N == len(a) - 1:
        print('NO')
    else:
        print('YES')


for i in range(int(input())):
    solve()