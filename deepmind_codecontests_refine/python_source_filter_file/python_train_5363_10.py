m, p, q = map(int, input().split())
s = str(input())

lp = 0
lq = 0
for i in range(m):
    for j in range(m):
        if i*p + j * q == m:
            lp = i
            lq = j
            break
    if lp+lq > 0:
        break


if lp+lq == 0:
    print (-1)
else:
    print(lp+lq)
    aux = 0
    for i in range(lp):
        print(s[aux:aux+p])
        aux = aux+p

    for i in range(lq):
        print(s[aux:aux+q])
        aux = aux+q
