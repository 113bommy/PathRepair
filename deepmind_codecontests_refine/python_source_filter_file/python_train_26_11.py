import math


def invalid(a, b, x):
    if (a+b==x):
        return 0
    else:
        return 1


r1 , r2 = input().split()
r1 = int(r1)
r2 = int(r2)

c1, c2 = input().split()
c1 = int(c1)
c2 = int(c2)

e1, e2 = input().split()
e1 = int(e1)
e2 = int(e2)

x = 9
flag = 1

while(x):
    x -= 1
    a1, a2, a3, a4 = 0, 0, 0, 9-x

    a2 = abs(c2 - a4)

    if invalid(a2, a4, c2):
        continue

    a1 = abs(r1 - a2)

    if invalid(a1, a2, r1) or invalid(a1, a4, e1):
        continue

    a3 = abs(c1 - a1)
    if invalid(a1, a3, c1) or invalid(a3, a2, e2) or invalid(a3, a4, r2):
        continue

    s = set()
    s.add(a1)
    s.add(a2)
    s.add(a3)
    s.add(a4)
    s = sorted(s)

    if len(s) == 4 and s[1] > 0 and s[3] <= 9:
        print(a1, a2)
        print(a3, a4)
        x = 0
        flag = 0

if flag:
    print(-1)

