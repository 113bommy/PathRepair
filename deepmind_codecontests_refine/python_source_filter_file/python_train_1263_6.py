b,k=map(int,input().split())
A=list(map(int,input().split()))
C=0
Z=1000000007
'''
def moduloMultiplication(a, b, mod): 
    res = 0 
    a = a % mod
    while (b): 
        if (b & 1): 
            res = (res + a) % mod 
        a = (2 * a) % mod
        b >>= 1  
    return res'''
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
      
for i in range(len(A)):
    x=power(b,k-1,Z)
    C+=A[i]*x
    k-=1

if(C%2==0):
    print("even")
else:
    print("odd")
