n = int(input())

ok = False
x = 0

for i in range(1000):
    if n == i * (i + 1) // 2:
        ok = True
        x = i
        break

if ok:
    print('Yes')
    d = n * 2 // x
    print(d)

    a = [[] for _ in range(d)]
    a[0].append(1)
    a[1].append(1)

    now = 1
    for i in range(2, d):
        for j in range(i):
            a[j].append(now + j + 1)
        for j in range(i):
            a[i].append(now + j + 1)
        now += i

    for i in range(d):
        print(x, *a[i])
else:
    print('No')
