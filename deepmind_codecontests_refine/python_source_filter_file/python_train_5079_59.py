from collections import deque
N, D, A = map(int, input().split())

ys = []
hs = []
for i in range(N):
    X, H = map(int, input().split())
    ys.append((X,i))
    hs.append(-(-H//A))

ys = sorted(ys, key=lambda x : x[0])
l = ys[0][0] + 2*D
li = 0
dmg = 0
r = 0
for y, i in ys:
    while l <= y:
        li += 1
        l = ys[li][0] + 2*D
        dmg -= hs[ys[li][1]]
    tr = max(0, hs[i]-dmg)
    hs[i] = tr
    dmg += tr
    r += tr
print(r)
