import sys

H,W=map(int,next(sys.stdin).split())

xs=[[0]*(W+2) for _ in range(H+2)]
ys=[[0]*(W+2) for _ in range(H+2)]
for i in range(1,H+1):
    row=next(sys.stdin)
    for j in range(1,W+1):
        if row[j-1]!='.': continue
        xs[i][j]=1+xs[i][j-1]
        ys[i][j]=1+ys[i-1][j]

ans=0
for i in range(H,0,-1):
    for j in range(W,0,-1):
        if xs[i][j]==0: continue
        x=xs[i][j]=max(xs[i][j],xs[i][j+1])
        y=ys[i][j]=max(ys[i][j],ys[i+1][j])
        ans=max(ans,x+y-1)

print(ans)
