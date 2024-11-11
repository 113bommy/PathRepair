'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineerin College
    Date:01/05/2020

'''
from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right
from itertools import permutations
from datetime import datetime
from math import ceil,sqrt,log,gcd
def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())


abc='abcdefghijklmnopqrstuvwxyz'
abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod=1000000007
#mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def powmod(a,b):
    a%=mod
    if(a==0):
        return 0
    res=1
    while(b>0):
        if(b&1):
            res=(res*a)%mod
        a=(a*a)%mod
        b>>=1
    return res

def solve():
    
    
    
    for _ in range(ii()):
        n,m=mi()
        a=li()
        m1={}
        for i in a:
            if i not in m1:
                m1[i]=1
            else:
                m1[i]+=1
        x=0
        a1=[]
        for i in m1.keys():
            x=max(x,m1[i])
            a1.append(i)
            
        if(len(a1)>m):
            print("-1")
            
        else:
            a1=a1+[1]*(m-len(a1))
            ans=[]
            print(a1)
            for i in range(100):
                for j in a1:
                    ans.append(j)
            print(len(ans))
            print(*ans)
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
if __name__== "__main__":
    solve()