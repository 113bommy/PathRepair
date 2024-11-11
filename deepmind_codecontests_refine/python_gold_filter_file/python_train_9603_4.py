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
    #arr=list(map(int,input().split()))
    #b=list(map(int,input().split()))
    #d={}1
    #flag=0
    total=0
    a,b,c,d=map(int,input().split())
    if(a<=b):
        print(b)
    elif(d>=c):
        print("-1")
    else:
        total = b + math.ceil((a-b)/(c-d))*c
        print(total)
