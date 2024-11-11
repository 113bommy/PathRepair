from math import inf
n, m = [int(x) for x in input().split()]
bad = False
ars = []
for i in range(m):
    k, *ar = [int(x) for x in input().split()]
    ars.append(ar)
for ar in ars:
    pol = set()
    otr = set()
    for x in ar:
        if x>0:
            pol.add(x)
        else:
            otr.add(-x)
    if len(pol & otr) == 0:
        bad = True
        break
print("YES" if bad else "NO")