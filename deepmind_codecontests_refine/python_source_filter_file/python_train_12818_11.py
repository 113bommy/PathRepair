n, x, y = map(int, input().strip().split())
ais = map(int, input().strip().split())

if x > y:
    print(n)
else:
    count = 0
    for ai in ais:
        if ai <= x:
            count += 1
    print(count // 2)

