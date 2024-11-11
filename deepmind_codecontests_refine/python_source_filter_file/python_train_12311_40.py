"""def power(x, y): 
    res = 1
    x=x
    while (y > 0): 
        if ((y & 1) == 1) : 
            res = (res * x) 
        y = y >> 1
        x = (x * x)
    return res""" 
"""def fact(n):
    if(n==0):
        return 1
    if(n==1):
        return 1
    return fact(n-1)+fact(n-2)"""

"""def sieveOfEratothenes(n):
    dp = [True]*(n+1)
    dp[1]=True
    p=2
    while(p*p<n+1):
        if(dp[p]==True):
            for i in range(p*p, n+1, p):
                dp[i]=False
        p+=1
    return dp"""

import math
#import combinations
 
 
t=int(input())
for _ in range(t):
    #n=int(input())
    #s=input()
    a,b,c=map(int,input().split())
    #arr=list(map(int,input().split()))
    a1=0
    a2=0
    if(a>=c):
        a1=-1
        a2=b
        print(a1,a2)
    else:
        a1=1
        
        if(c//b>=a):
            a2=-1
            print(a1,a2)
        else:
            a2=c
            print(a1,a2)
            
        
        
        
        
