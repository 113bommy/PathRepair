import math
n,m=map(int,input().split())
ans=0
for i in range(n+1):
    temp=int(math.sqrt(n-i))
    if temp*temp==(n-i):
        if temp+(i**2)==m:
            ans+=1

print(ans)