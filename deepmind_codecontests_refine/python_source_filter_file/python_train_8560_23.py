from sys import stdin
import math
a=int(stdin.readline())

for b in range(0,a):
    c=stdin.readline().split()
    d=int(c[0])
    e=int(c[1])
    f=int(c[2])

    while True:
        if e+f==0 or d<=0:
            break

        if d>=39:
            if e>0:
                d=math.floor(d/2)+10
                e-=1
            else:
                d-=10
                f-=1

        else:
            if f>=math.floor(d)+1 or e==0:
                d-=10
                f-=1
            else:
                d = math.floor(d / 2) + 10
                e-=1

    if d<=0:
        print('YES')
    else:
        print('NO')