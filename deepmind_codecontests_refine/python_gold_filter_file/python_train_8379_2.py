import math
def power(x, y, p) : 
    res = 1 
    x = x % p  
  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1      
        x = (x * x) % p 
          
    return res
#q=int(input())
q=1
for _ in range(q):
    mod=10**9+7
    a=int(input())
    ans=power(27, a, mod)
    ans-=power(7,a,mod)
    print(ans%mod)