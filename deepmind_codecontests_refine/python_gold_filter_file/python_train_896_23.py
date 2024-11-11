n,m=map(int,input().split())
l=0
r=0
a,b=map(int,input().split())
l=a
r=b
for i in range(n-1):
    a,b=map(int,input().split())
    if(a<=r and a>=l):
        r=max(b,r)
if(l<=m<=r and l==0):
    print("YES")
else:
    print("NO")