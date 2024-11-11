d = [0]*10**5

a = set()
w = 0

for t in open(0):
    p, s = t.split
    p = int(p)
    if "AC" == s and p not in a:
        w += d[p]
        a.add(p)
    if "WA" == s:
        d[p] += 1

print(len(a), w)