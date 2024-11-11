t = int(input().strip())

for _ in range(t):
    n = int(input().strip())
    if (n / 2) % 2 != 0:
        print('NO')
        continue
    print('YES')
    l = []
    p = 0
    for i in range(n // 2):
        p += 2
        l.append(p)
    s = sum(l)
    p = -1
    for i in range(n // 2 - 1):
        p += 2
        l.append(p)
    l.append(s - sum(l[n // 2:]))
    print(", ".join(map(str, l)))

