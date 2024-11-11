import math
import decimal
D=decimal.Decimal
t = int(input())
for x in range(t):
    l1 = [int(x) for x in input().split()]
    n = l1[0]; k = l1[1]
    nearest = n
    ans = 0
    while nearest>=1:
        #print(nearest,ans)
        ans+=nearest%k
        nearest-=nearest%k
        nearest=int(D(nearest//k))    
        ans+=1
    print(ans-1)
