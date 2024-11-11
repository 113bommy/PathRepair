n, x, y = map(int, input().split())
a = list(map(int, input().split()))

if x > y:
    print(n)
else:
    cnt = 0
    for el in a:
        if el < x:
            cnt += 1

    print((cnt + 1) // 2)


