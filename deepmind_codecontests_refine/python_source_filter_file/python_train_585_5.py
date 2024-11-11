# -*- coding: utf-8 -*-

a = input().split()
k = int(a[0])
d = int(a[1])
t = int(a[2])

if k<d:
    pp = float(k + (d-k)/2.0)
    times = int(t/pp)
    pp = t - times*pp
    ans = float(times*d)
    if pp>k:
        ans = ans + (pp-k)*2.0 + k
    else:
        ans = ans + pp
    print("%.9f"%ans)
else:
    if k%d == 0:
        print("%.9f"%t)
    else:
        pp = float(k + (d-k%d)/2.0)
        times = int(t/pp)
        pp = t - times*pp
        ans = float(times*(int(k/d)+1)*d)
        if(pp>k):
            ans = ans + k + (pp-k)/2.0
        else:
            ans = ans + pp
        print("%.9f"%ans)

