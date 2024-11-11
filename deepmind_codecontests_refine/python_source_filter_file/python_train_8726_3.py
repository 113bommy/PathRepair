H, W, D = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(H)]
x = [0]*(H*W+D+1)
y = [0]*(H*W+D+1)
for k in range(W):
    for l in range(H):
        x[A[l][k]] = k+1
        y[A[l][k]] = l+1

d = [0]*(H*W+D+1)
for k in range(H*W,1,-1):
    d[k] = d[k+D] + abs(x[k]-x[k+D]) + abs(y[k]-y[k+D])

for _ in range(int(input())):
    L, R = map(int,input().split())
    print(d[L]-d[R])
