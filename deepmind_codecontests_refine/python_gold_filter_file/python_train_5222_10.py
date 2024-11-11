n,h,m=(int(i) for i in input().split())
buildings=[h for i in range(n+1)]
for i in range(m):
    l,r,x=(int(j) for j in input().split())
    for j in range(l,r+1):
        buildings[j]=min(x,buildings[j])
s=0
for i in range(1,n+1):
    s+=buildings[i]**2
print(s)
