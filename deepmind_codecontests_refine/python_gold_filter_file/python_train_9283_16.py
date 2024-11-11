n = int(input())
if n % 2 == 0:
    print('NO')
else:
    print('YES')
    l = 1
    r = 2 * n
    while True:
        if l < r:
            print(l, end= ' ')
        else:
            break
        if l < r - 2:
            print(r, end=' ')
        l += 2
        r -= 2
    l = 2
    r = 2 * n - 1
    while True:
        if l < r:
            print(l, end=' ')
        else:
            break
        if l < r - 2:
            print(r, end= ' ')
        l += 2
        r -= 2
    print(l)
    