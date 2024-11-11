################OM NAMAH SHIVAAY##################37
###############(BHOLE KI FAUJ KREGI MAUJ)############37
from sys import stdin,stdout 
import math,queue,heapq
fastinput=stdin.readline
fastout=stdout.write
def isPrime(n) : 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True
def computeLPSArray(pat, M, lps): 
    len = 0 
    lps[0] 
    i = 1
    while i < M: 
        if pat[i]== pat[len]: 
            len += 1
            lps[i] = len
            i += 1
        else: 
            if len != 0: 
                len = lps[len-1] 
  
            else: 
                lps[i] = 0
                i += 1

#t=int(fastinput()) 
#mod=10**9 +7
mod=998244353

t=1 
while t:
    t-=1 
    n=int(fastinput()) 
    #n,m=map(int,fastinput().split())  
    #a=[0]+list(map(int,fastinput().split()))
    j=0
    a=[]
    for i in fastinput().split(): 
    
        a.append((int(i)*(j+1)*(n-j)))
        j+=1 
    a.sort()
    
    b=list(map(int,fastinput().split()))
    b.sort(reverse=True)
    #matrix=[list(map(int,fastinput().split())) for _ in range(n)]  
    ans=0 
    for i in range(n):
        ans=(ans+a[i]*b[i])%mod
    print(ans%mod)
    
    