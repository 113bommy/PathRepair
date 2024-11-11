q = int(input())
res = []
for _ in range(q):
    m = int(input())
    a = 0
    check = m % 2
    if m == 2:
        a = 2
    else:
        if not check:
            a = 1
    res.append(a)
for i in res:
    print(i)