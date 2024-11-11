n = 8
group = 3
middle = 1
dx = {}
dy = {}
pairs = []
isUgly = False
for i in range(n):
    x, y = map(int, input().split())
    if x in dx:
        dx[x] += 1
        if dx[x] > group:
            isUgly = True
    else:
        dx[x] = 1
    if y in dy:
        dy[y] += 1
        if dy[y] > group:
            isUgly = True
    else:
        dy[y] = 1
    pair = str(x) + str(y)
    pairs.append(pair)
if len(dx) == group and len(dy) == group and len(pairs) == n and not isUgly:
    arrX = list(dx.keys())
    arrX.sort()
    arrY = list(dy.keys())
    arrY.sort()
    x2 = arrX[middle]
    y2 = arrY[middle]
    pair = str(x2) + str(y2)
    for e in pairs:
        if e == pair:
            isUgly = True
            break
    if isUgly:
        print('ugly')
    else:
        print('respectable')
else:
    print('ugly')