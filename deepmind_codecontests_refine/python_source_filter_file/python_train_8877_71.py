from collections import Counter
import string
import math
import sys
# sys.setrecursionlimit(10**6)
from fractions import Fraction
def array_int():
    return [int(i) for i in sys.stdin.readline().split()]
def vary(arrber_of_variables):
    if arrber_of_variables==1:
        return int(sys.stdin.readline())
    if arrber_of_variables>=2:
        return map(int,sys.stdin.readline().split()) 
def makedict(var):
    return dict(Counter(var))
# i am noob wanted to be better and trying hard for that
def printDivisors(n): 
    divisors=[]  
    # Note that this loop runs till square root 
    i = 1
    while i <= math.sqrt(n): 
          
        if (n % i == 0) : 
              
            # If divisors are equal, print only one 
            if (n//i == i) : 
                divisors.append(i) 
            else : 
                # Otherwise print both 
                divisors.extend((i,n//i)) 
        i = i + 1
    return divisors
 
def countTotalBits(num):
     binary = bin(num)[2:]
     return(len(binary))
def isPrime(n) : 
  
    # Corner cases 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True
""" mod=10**9+7
def ncr(n,r):
    if n<r:
        return 0
    numer=fact[n]
    # print(numer)
    denm=(fact[n-r]*fact[r])
    # print(denm)
    return numer*pow(denm,mod-2,mod) """
""" def dfs(node):
    global graph
    mex=0
    size=1
    for i in graph[node]:
        t=dfs(i)
        mex=max(mex,t[0])
        size+=t[1]
    return [mex+size,size] """
    
""" fact=[1]*(1001)
c=1 
mod=10**9+7
for i in range(1,1001):
    fact[i]=(fact[i-1]*i)%mod """
# print(fact)
tt=vary(1)
for tc in range(tt):
    a,b,c,d=vary(4)
    print(a+b)
   
    
    
        

        
        

    
    
    

    


    

    

   




