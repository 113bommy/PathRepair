n=int(input())
import math
ans=0
for i in range(1,n-1):
    if math.gcd(i,n-1)==1:
        ans+=1
print(ans)