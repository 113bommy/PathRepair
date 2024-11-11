H, W, D = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
Q = int(input())

p = {}
for i in range(H):
    for j in range(W):
        p[A[i][j]-1] = (i, j)

d = [0]*(H*W)
for i in range(D+1, H*W):
    d[i] = d[i-D] + abs(p[i][0]-p[i-D][0]) + abs(p[i][1]-p[i-D][1])

for _ in range(Q):
    L, R = map(lambda x:int(x)-1, input().split())
    print(d[R]-d[L])