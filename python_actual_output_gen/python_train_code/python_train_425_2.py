s = input()
l = 0
r = 0
u = 0
d = 0
for c in s:
    if c == 'R':
        r += 1
    elif c == 'L':
        l += 1
    elif c== 'U':
        u += 1
    elif c == 'D':
        d += 1
d1 = max(l,r) - min(l,r)
d2 = max(u,d) - min(u,d)
if d1 + d2 % 2 != 0:
    print(-1)
else:
    print((d1+d2)//2)

