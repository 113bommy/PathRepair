from math import factorial as fact
n,m=[int(i) for i in input().split()]
mod=1000000007
a=fact(n+2*m-1)
b=fact(2*m) 
c=fact(n-1)
b=b*c
a=a/b
print(a%mod)
        
        
        
        
        

        
        