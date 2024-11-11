def power(x, y, p) : 
    res = 1     # Initialize result 
  
    # Update x if it is more 
    # than or equal to p 
    x = x % p  
  
    while (y > 0) : 
          
        # If y is odd, multiply 
        # x with result 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
  
        # y must be even now 
        y = y >> 1      # y = y/2 
        x = (x * x) % p 
          
    return res  
import math
#q=int(input())
q=1
for _ in range(q):
    mod=10**9+7
    n,m=map(int,input().split())
    c=(power(2, m, mod)-1)%mod
    ans=power(c,n,mod)%mod
    print(ans%mod)    
    