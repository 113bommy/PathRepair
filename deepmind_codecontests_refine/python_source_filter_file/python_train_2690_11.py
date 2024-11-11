H, W=map(int,input().split())
c=[list(map(int,input().split())) for i in range(10)]
a=[list(map(int,input().split())) for i in range(H)]
ans=0

for i in range(10):
    for j in range(10):
        for k in range(10):
            c[i][j]=min(c[i][j],c[i][k]+c[k][j])

for i in range(H):
    for j in range(W):
        if a[i][j]>=0:
            ans += c[a[i][j]][1]

print(ans)