vv = [int(x) for x in input().split()]
n = vv[0]
m = vv[1]
z = vv[2]
if n == 1:
    print(z//m)
else:
    sp1 = [int(k) for k in range(n, z+1, n)]
    sp11 = set(sp1)
    sp2 = [int(d) for d in range(m, z+1, m)]
    sp22 = set(sp2)
    res = sp11.intersection(sp22)
    print(len(res))