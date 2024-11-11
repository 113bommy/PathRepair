
s, x1, x2 = [int(x) for x in input().split()]
t1, t2 = [int(x) for x in input().split()]
p, d = [int(x) for x in input().split()]

di = (x2 - x1 > 0) * 2 - 1
ti = abs(x2 - x1) * t2


if (d == di):
    if ((p - x1) * d <= 0):
        tt = (x2 - p) * d * t1
    else:
        tt = (2*s + (x2 - p)*d) * t1
else:
    if (d == 1):
        tt = (2*s - (p + x2)) * t1
    else:
        tt = (p + x2) * t1


T = min(ti, tt)
print(T)