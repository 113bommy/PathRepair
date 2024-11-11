a = [int(s) for s in input().split()]
n = a[0]
v = a[1]
s = n - 1
d = min(v, s)
su = 0
n1 = 0
if s > v:
    n1 = s - v
    an = n1
    a1 = 2
    su = ((a1 + an) * n1) // 2
    print(su + v)
else:
    print(d)
