H,W=map(int,input().split())
a=[list(map(int,input().split())) for _ in[0]*H]
res=[]
for i in range(H):
    for j in range(W-1):
        if a[i][j]%2==1:
            a[i][j]-=1
            a[i][j+1]+=1
            res.append([i,j,i,j+1])
for i in range(H-1):
    if a[i][-1]%2==1:
        a[i][-1]-=1
        a[i+1][-1]+=1
        res.append([i,j,i+1,j])
print(len(res))
for a,b,c,d in res:
    print(a+1,b+1,c+1,d+1)