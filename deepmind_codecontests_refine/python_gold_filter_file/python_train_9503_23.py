from sys import stdin,stdout
from collections import defaultdict
input=stdin.readline
print=stdout.write
n=int(input())
ways=1
def nCr(n, r): 
  
    return (fact(n) / (fact(r)  
                * fact(n - r))) 
  
# Returns factorial of n 
def fact(n): 
    res = 1
    for i in range(2, n+1): 
        res = res * i 
          
    return res 
ways= ways * nCr( n, n//2)
ways=ways//2
ways= ways * fact((n//2) -1)*fact((n//2)-1)
ways=int(ways)
print(str(ways//1)+"\n")