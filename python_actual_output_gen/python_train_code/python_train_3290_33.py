n = int(input())
for i in range(n):
    x = list(map(str, input().split()))
    if int(x[2]) > int(x[1]) > 2400:
        print('YES')
        break
    elif (not int(x[2]) > int(x[1]) > 2400) and i == n - 1:
        print('NO')
