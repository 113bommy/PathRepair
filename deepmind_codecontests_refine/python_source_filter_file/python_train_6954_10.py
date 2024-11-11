h,w=map(int,input().split())
s=[input() for _ in range(h)]
yoko=[[0]*w for _ in range(h)]
tate=[[0]*w for _ in range(h)]
count=0
for i in range(h):
    a=[0]
    for j in range(w):
        if s[i][j]=="#":
            a.append(j+1)
    a.append(w+1)
    for j in range(1,len(a)):
        for k in range(a[j-1],a[j]-1):
            yoko[i][k]=a[j]-a[j-1]-1
for i in range(w):
    a=[0]
    for j in range(h):
        if s[j][i]=="#":
            a.append(j+1)
    a.append(h+1)
    for j in range(1,len(a)):
        for k in range(a[j-1],a[j]-1):
            tate[k][i]=a[j]-a[j-1]-1

ans=1
for i in range(w):
    for j in range(h):
        ans=max(ans,yoko[i][j]+tate[i][j]-1)
print(ans)
