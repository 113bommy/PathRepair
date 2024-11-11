a, b = map(int,input().split())
c = [[0] * (b) for i in range(a)]
d = [input() for i in range(a)]
for j in range (b):
    n = []
    pred = d[0][j]
    cnt = 1
    for i in range(1, a):
        if d[i][j] == pred:
            cnt += 1
        else:
            n.append((cnt, pred))
            cnt = 1
        pred = d[i][j]
    n.append((cnt, pred))
    uk = 0
    for i in range(2, len(n)):
        if n[i - 2][0]>= n[i - 1][0] and n[i - 1][0] >= n[i - 2][0]:
            c[uk + n[i - 2][0] - n[i - 1][0]][j] = [n[i - 2][1], n[i - 1][1], n[i][1], n[i - 1][0]]
        uk += n[i - 2][0]
summ = 0
cnt = 0
if b == 1:
    for i in range(a):
        for j in range(b):
            if c[i][j] != 0:
                summ += 1
    print(summ)
    exit(0)
for i in range(a):
    cnt = 0
    f = False
    for j in range(1, b):
        if cnt == 0 and c[i][j - 1] != 0:
            cnt = 1
        if c[i][j - 1] == c[i][j] and c[i][j] != 0:
            cnt += 1
        elif c[i][j] != 0:
            summ += cnt * (cnt + 1) // 2
            cnt = 1
        else:
            summ += cnt * (cnt + 1) // 2
            cnt = 0
    summ += cnt * (cnt + 1) // 2
print(summ)
