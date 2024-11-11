n,m=map(int,input().split())
l,r=1,n
for i in range(m):
    a,b=map(int,input().split())
    l=max(l,a)
    r=min(r,b)
print(r-l+1)