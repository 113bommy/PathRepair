t = int(input())
while t:
    t += -1
    n = int(input())
    l = list(map(int, input().split()))
    l1 = []
    for i in l: l1.append(i)
    l1.sort()
    ind = []
    for i in range(n):
        if l[i] != l1[i]: ind.append(i)
    mn = min(l)
    check = 1
    for i in ind:
        if l[i] % 2:
            check = 0
            break
    if check: print('YES')
    else: print('NO')