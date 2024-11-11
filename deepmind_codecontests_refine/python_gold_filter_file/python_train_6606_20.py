orig = input()
pnt = 0
for i in orig:
    if i == '+':
        pnt += 1
    else:
        pnt -= 1

cmd = input()
pnt2 = 0
q = 0
for i in cmd:
    if i == '+':
        pnt2 += 1
    elif i == '-':
        pnt2 -= 1
    else:
        q += 1

match = 0
for bit in range(1<<q):
    p = pnt2
    for i in range(q):
        if bit&(1<<i):
            p += 1
        else:
            p -= 1
    if p == pnt:
        match += 1


if q == 0:
    print(1 if pnt == pnt2 else 0)
else:
    print(match/(2**q))
    