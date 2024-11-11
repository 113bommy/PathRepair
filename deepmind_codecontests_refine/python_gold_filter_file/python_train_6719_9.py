from collections import defaultdict
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
n,k=M()
a=LI()
d=defaultdict(int)
k-=1
c=0;ans=0
while k+c<n and k-c>=0:
    if a[k+c]==a[k-c]:
        if c==0:
            ans+=(a[k+c])
        else:
            ans+=(a[k+c]*2)
    c+=1
for i in range(0,(k-c)+1):
    if a[i]==1:
        ans+=1
for i in range(k+c,n):
    if a[i]==1:
        ans+=1
print(ans)


