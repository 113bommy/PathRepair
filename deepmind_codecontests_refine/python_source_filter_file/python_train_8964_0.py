import math  
  
# method to print the divisors 
def ps(n) : 
    a=[]
    # Note that this loop runs till square root 
    i = 1
    while i <= math.sqrt(n): 
          
        if (n % i == 0) : 
              
            # If divisors are equal, print only one 
            if (n / i == i) : 
                a.append(i) 
            else : 
                # Otherwise print both 
                a.extend([i , n//i]) 
        i = i + 1
    return a

def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)
    
def sol(a, b, n): 
  
    i = 0
    while i * a <= n: 
           
        if (n - (i * a)) % b == 0: 
            return int((n - (i * a)) / b)
        i = i + 1
      


n=int(input())
a=ps(n)
a.sort()
e=-1
d=len(a)
for i in range(1,(len(a)+1)//2):
    if gcd(a[i],a[d-1-i])==1:
        e=a[i]
        f=a[d-i-1]
if e==-1:
    print("NO")
else:
    a=sol(e,f,n-1)
    b=(n-1-a*f)//e
    print("YES")
    print(2)
    print(a,b)
    print(e,f)