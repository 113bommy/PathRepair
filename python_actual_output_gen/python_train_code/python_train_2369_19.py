n = int(input())
if n > 34:
    print(-1)
else:
    if n % 2 == 0:
        print(n // 2 * '8')
    else:
        print(n // 2 * '8' + '4')
