h, w = map(int, input().split())
a = [input() for i in range(h)]
b = [-1]*h*w; c = []; d = 0
for i in range(h):
    for j in range(w):
        if a[i][j] == "#": b[i*w+j] = 0; c.append(i*w+j)
while len(c) < h*w:
    if c[d]//w != 0:
        if b[c[d]-w] == -1: b[c[d]-w] = b[c[d]]+1; c.append(c[d]-w)
    if c[d]%w != 0:
        if b[c[d]-1] == -1: b[c[d]-1] = b[c[d]]+1; c.append(c[d]-1)
    if c[d]%w != w-1:
        if b[c[d]+1] == -1: b[c[d]+1] = b[c[d]]+1; c.append(c[d]+1)
    if c[d]//w != h-1:
        if b[c[d]+w] == -1: b[c[d]+w] = b[c[d]]+1; c.append(c[d]+w)
    d += 1
print(max(b))