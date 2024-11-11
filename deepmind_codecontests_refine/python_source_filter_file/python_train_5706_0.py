def men(t):
    xmin = min(st + i * t for i, st in enumerate(mg[0]))
    xmax = max(st + i * t for i, st in enumerate(mg[1]))
    ymin = min(st + i * t for i, st in enumerate(ue[0]))
    ymax = max(st + i * t for i, st in enumerate(ue[1]))
    return (xmax - xmin) * (ymax - ymin)

n = int(input())
inf = 10**9
mg = [[inf, inf, inf], [-inf, -inf, -inf]]
ue = [[inf, inf, inf], [-inf, -inf, -inf]]
mg0=mg[0]
mg1=mg[1]
ue0=ue[0]
ue1=ue[1]
for _ in range(n):
    x, y, d = input().split()
    x = int(x)
    y = int(y)
    if d == "U":
        mv = 1
        uv = 2
    elif d == "D":
        mv = 1
        uv = 0
    elif d == "R":
        mv = 2
        uv = 1
    else:
        mv = 0
        uv = 1
    if x < mg0[mv]: mg0[mv] = x
    if x > mg1[mv]: mg1[mv] = x
    if y < ue0[uv]: ue0[uv] = y
    if y > ue1[uv]: ue1[uv] = y
t=set()
for lst in [mg0,mg1,ue0,ue1]:
    v0,v1,v2=lst
    for tk in [v0-v1,v1-v2,(v0-v2)/2]:
        if tk>=0:
            t.add(tk)
print(min(men(tk) for tk in t))