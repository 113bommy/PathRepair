T = int(input())
from math import log
for t in range(T):
    A,B = [int(x) for x in input().split()]
    ans = A*int(log(B,10))
    if(log(B+1,10)==int(log(B+1,10))):
        ans+=1
    print(ans)
