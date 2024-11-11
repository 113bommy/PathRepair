n, a, x, b, y = map(int, input().split())
for i in range(min((x-a)%n, (b-y)%n)+1):
    if a == b:
        print('YES')
        exit()
    else:
        a += 1
        b -= 1
        if a > n:
            a = 1
        if b < 1:
            b = n
print('NO')
