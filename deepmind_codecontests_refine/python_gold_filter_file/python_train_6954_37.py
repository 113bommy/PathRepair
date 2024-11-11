h, w = map(int, input().split())
s = [input() for _ in range(h)]
sy = [0] * w
ret = 0
for y in range(h):
    seqx = 0
    seqy = 0
    for x in range(w):
        if s[y][x] == '.':
            if sy[x] == 0:
                yy = y
                while yy < h and s[yy][x] != '#':
                    yy += 1
                sy[x] = yy - y
            seqx += 1
            seqy = max(seqy, sy[x])
            ret = max(ret, seqx + seqy - 1)
        else:
            seqx = 0
            seqy = 0
            sy[x] = 0
print(ret)
