N = int(input())
EPS = 1e-6
for i in range(N):
    x1,y1,x2,y2,x3,y3,x4,y4 = map(float,input().split())
    if x2 == x1 and x4 == x3:
        print('YES')
        continue
    elif x2 == x1 or x4 == x3:
        print('NO')
        continue
    f = (y2 - y1) / (x2 - x1)
    g = (y4 - y3) / (x4 - x3)
    if g - EPS <= f <= g + EPS:
        print('YES')
    else:
        print('NO')