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
     
 


a=list(map(int,input().split()))
n=a[0];m=a[1];k=a[2]
if k==-1 and (n%2==0 and m%2!=0) or (n%2!=0 and m%2==0):
    print(0)
else:
    print(power(2,(n-1)*(m-1),((10**9)+7)))