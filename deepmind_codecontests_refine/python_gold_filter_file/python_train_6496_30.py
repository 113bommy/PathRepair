n,m=map(int,input().split())
l=list(map(int,input().split()))
a=1
s=0
for i in range(m):
    if l[i]>=a:
        s=s+l[i]-a
    else:
        s=s+(n-a+l[i])
    a=l[i]
print(s)