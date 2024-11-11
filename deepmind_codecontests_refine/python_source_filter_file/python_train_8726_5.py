import sys
def Is(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())

H,W,D = Is()
d = dict()
for i in range(H):
    s = Is()
    for j,e in enumerate(s):
        d[e] = (i,j)
m = [0]*H*W
for i in range(D+1,H*W):
    m[i] = m[i-D] + abs(d[i-D][0] - d[i][0]) + abs(d[i-D][1] - d[i][1])

Q = I()
for q in range(Q):
    l,r = Is()
    print(m[r]-m[l])
