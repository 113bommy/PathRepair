n,t,c=map(int,input().split())
a=list(map(int,input().split()))
b=[0]*n
if a[0]<t:
    b[0]=c+1
for i in range(1,n):
    if a[i]<=t:
        b[i]=b[i-1]+1
ans=0
for i in range(c-1,n):
    if b[i]>=c:
        ans+=1
print(ans)