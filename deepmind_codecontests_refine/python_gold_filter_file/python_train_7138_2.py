from math import sin

n = int(input())
c = 0
R = 20000
eps = 0.000001
for i in range(n):
    t, d = [j for j in input().split(" ")]
    t = int(t)
    if (d == "South"):
        if (abs(c - 1) < eps or t > 20000):
            c = 1
            break
        c += t / R
    elif (d == "North"):
        if (c < eps or t > 20000):
            c = 1
            break
        c -= t / R
    else:
        if (c < eps or abs(c - 1) < eps):
            c = 1
            break
    if (c > 1 + eps or c < -eps):
        c = 1
        break

if (c < eps):
    print("YES")
else:
    print("NO")
