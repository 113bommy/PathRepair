n,m,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
x,y=[0],[0]
for i in range(n):
    x.append(a[i]+x[i])
for j in range(m):
    y.append(b[j]+y[j])

ans=0
j=m
for i in range(n+1):
    if x[i]>k:
        break
    while y[j]>k-x[i]:
        j-=1
    ans=max
print(ans)