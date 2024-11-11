x, y, m = map(int,input().split())
mat = set()
r = [0]*x
c = [0]*y
smx = 0
smy = 0
for _ in range(m):
    p, q = map(int,input().split())
    p -= 1
    q -= 1
    mat.add((p,q))
    r[p] += 1
    c[q] += 1
    smx = max(smx,r[p])
    smy = max(smy,c[q])
xs = []
ys = []
for i in range(x):
    if smx == r[i]: xs.append(i)
for i in range(y):
    if smy == c[i]: ys.append(i)

ans = smx + smy - 1

for h in xs:
    for w in ys:
        if (h, w) in mat: continue
        print(ans + 1)
        exit()
print(ans)
