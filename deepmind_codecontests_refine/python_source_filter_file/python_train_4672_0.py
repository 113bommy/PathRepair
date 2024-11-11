import sys

def crossMulti(p1, p2):
    return p1[0] * p2[1] - p1[1] * p2[0]
           
lines = sys.stdin.readlines()
for line in lines:
    Zd = []
    x1, y1, x2, y2, x3, y3, xp, yp = map(float, line.split())
    Ps = [(x2-x1, y2-y1),(x3-x2, y3-y2),(x1-x3, y1-y3)]
    Px = [(xp-x1, yp-y1),(xp-x2, yp-y2),(xp-x3, yp-y3)]
    for p in range(3):
        Zd.append(crossMulti(Ps[p], Px[p]))
    Zd = [x > 0 for x in Zd]

    if (Zd[0] and Zd[1] and Zd[2]) or not(Zd[0] or Zd[1] or Zd[2]):
        print('Yes')
    else:
        print('No')
    