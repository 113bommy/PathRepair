t = int(input())
xp = []
xo = []
for i in range(t):
    a, b = map(int, input().split())
    if a>0:
        xp.append(a)
    else:
        xo.append(a)
if len(xp) == 1 or len(xo) == 1:
    print('Yes')
else:
    print('No')