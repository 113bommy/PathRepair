h, w = map(int,input().split())
g = [input() for i in range(h)]
 
d = [[200] * w for i in range(h)]

d[0][0] = ( g[0][0] == "#")
for i in range(h):
    for j in range(w):
        if i + 1 < h:
            d[i+1][j] = min(d[i+1][j], d[i][j]+(g[i+1][j] == '#' and g[i][j] == '.'))
        if j + 1 < w:
            d[i][j+1] = min(d[i][j+1], d[i][j]+(g[i][j+1] == '#' and g[i][j] == '.'))

print(d[-1][-1])