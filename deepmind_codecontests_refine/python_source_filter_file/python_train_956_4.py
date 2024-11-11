from sys import stdin,stdout
from sys import stdin
n,m,d=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
acum=[0 for i in range(m)]
acum[-1]=s[-1]

for i in range(m-2,-1,-1):
    acum[i]=s[i]+acum[i+1]
acum.append(0)
l=0
ans=[0 for i in range(n)]
aux=[]
mx=0
for i in range(m):
    rr=9
    for j in range(l,l+d):
        y=s[i]+j
        rr=j
        if((n-y)-1)<acum[i+1]:
            break
    l=y
    mx=y
    aux.append(rr)
mx+=d
ans=[0 for i in range(n)]
for i in range(m):
    for j in range(aux[i],s[i]+aux[i]):
        ans[j]=i+1
if(mx>=n):
    print("YES")
    print(*ans)

else:
    print("NO")
            
        
