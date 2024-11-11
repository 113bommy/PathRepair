n, c, d = map(int, input().split())
coin = [[(0, 0), (0, 0)] for i in range(100001)]
diam = [[(0, 0), (0, 0)] for i in range(100001)]
f = []
for i in range(n):
    b, c, q = input().split()
    b = int(b)
    c = int(c)
    if q == 'C':
        f.append((b, c, 1))
        if coin[c][0][0] < b:
            coin[c][1] = coin[c][0]
            coin[c][0] = (b, i)
        elif coin[c][1][0] < b:
            coin[c][1] = (b, i)
    else:
        f.append((b, c, 2))
        if diam[c][0][0] < b:
            diam[c][1] = diam[c][0]
            diam[c][0] = (b, i)
        elif diam[c][1][0] < b:
            diam[c][1] = (b, i)
for i in range(2, 100001):
    if coin[i][0][0] < coin[i - 1][0][0]:
        coin[i][1] = max(coin[i][0], coin[i - 1][1])
        coin[i][0] = coin[i - 1][0]
    else:
        coin[i][1] = max(coin[i - 1][1], coin[i][1])
    if diam[i][0][0] < diam[i - 1][0][0]:
        diam[i][1] = max(diam[i][0], diam[i - 1][1])
        diam[i][0] = diam[i - 1][0]
    else:
        diam[i][1] = max(diam[i - 1][1], diam[i][1])
p = False
ans = 0
for i in range(n):
    fnt = f[i]
    #print(fnt)
    if fnt[2] == 1:
        if c > fnt[1]:
            s = c - fnt[1]
            if coin[s][0][0] > 0 and coin[s][0][1] != i:
                ans = max(fnt[0] + coin[s][0][0], ans)
                p = True
            elif coin[s][1][0] > 0:
                ans = max(fnt[0] + coin[s][1][0], ans)
                p = True
            if diam[d][0][0] > 0:
                ans = max(fnt[0] + diam[d][0][0], ans)
                p = True
    else:
        if d > fnt[1]:
            s = d - fnt[1]
            if diam[s][0][0] > 0 and diam[s][0][1] != i:
                ans = max(fnt[0] + diam[s][0][0], ans)
                p = True
            elif diam[s][1][0] > 0:
                ans = max(fnt[0] + diam[s][1][0], ans)
                p = True
            if coin[c][0][0] > 0:
                ans = max(fnt[0] + coin[c][0][0], ans)
                p = True
if p:
    print(ans)
else:
    print(0)