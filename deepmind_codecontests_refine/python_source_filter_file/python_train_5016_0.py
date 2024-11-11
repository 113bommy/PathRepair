n, k = map(int, input().split())
p = list(map(int,input().split()))
q = list(map(int, input().split()))
sp = set()
sq = set()
chuj = 0
odp = [chr(96 + 26) for i in range(n)]
for i in range(n):
    odp[p[i] - 1] = chr(97 + chuj)
    if p[i] - 1 in sq:
        sq.remove(p[i] - 1)
    else:
        sp.add(p[i] - 1)
    if q[i] - 1 in sp:
        sp.remove(q[i] - 1)
    else:
        sq.add(q[i] - 1)
    if len(sp) + len(sq) == 0:
        chuj += 1
    if chuj == 25:
        break
if chuj < k:
    print("NO")
else:
    print("YES")
    print("".join(odp))