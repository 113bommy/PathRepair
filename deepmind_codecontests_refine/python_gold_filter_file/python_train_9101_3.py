from sys import maxsize, stdout, stdin,stderr
mod = int(1e9+7)
import sys
def I(): return int(stdin.readline())
def lint(): return [int(x) for x in stdin.readline().split()]
def S(): return input().strip()
def grid(r, c): return [lint() for i in range(r)]
from collections import defaultdict, Counter, deque
import math
import heapq
from heapq import heappop , heappush
import bisect
from itertools import groupby
def gcd(a,b): 
    while b:
        a %= b
        tmp = a
        a = b
        b = tmp
    
    return a
 
def lcm(a,b): 
    return a  // gcd(a, b) * b
 
def check_prime(n):
    for i in range(2, int(n ** (1 / 2)) + 1):
        if not n % i:
            return False
    return True
def Bs(a, x):
    i=0
    j=0
    left = 1
    right = x
    flag=False
    while left<right:
        
        mi = (left+right)//2
        #print(smi,a[mi],x)
        
        if a[mi]<=x:
            left = mi+1
            i+=1
            
        else:
 
            right = mi
            j+=1
        #print(left,right,"----")
    #print(i-1,j)
    if left>0 and a[left-1]==x:
        return i-1, j
    else:
        return -1, -1
def nCr(n, r):
 
    return (fact(n) // (fact(r)
                * fact(n - r)))
 
# Returns factorial of n
def fact(n):
 
    res = 1
     
    for i in range(2, n+1):
        res = res * i
         
    return res
def primefactors(n):
    num=0
    
    while n % 2 == 0:
        num+=1
        n = n / 2
    
    for i in range(3,int(math.sqrt(n))+1,2):
         
    
        while n % i== 0:
            num+=1
            n = n // i
               
    
    if n > 2:
        num+=1
    return num
'''
def iter_ds(src):
    store=[src]
    while len(store):
        tmp=store.pop()
        if not vis[tmp]:
            vis[tmp]=True
            for j in ar[tmp]:
                store.append(j)
'''
def ask(a):
    print('? {}'.format(a),flush=True)
    n=I()
    
    return n


 
def dfs(i,p):
    
    a,tmp=0,0
    for j in d[i]:
        if j!=p:
            a+=1
            tmp+=dfs(j,i)
    
    if a==0:
        return 0
    
    return tmp/a + 1 
def primeFactors(n):
    l=[]
    
    while n % 2 == 0:
        l.append(2)
        n = n // 2
         

    if n > 2:
        l.append(n)
    return l
n,m=lint()
a=[]
dp1=[[0]*(m+2) for _ in range(n+2)]
dp2=[[0]*(m+2) for _ in range(n+2)]
dp3=[[0]*(m+2) for _ in range(n+2)]
dp4=[[0]*(m+2) for _ in range(n+2)]
ans=0
for i in range(n):
    a.append(lint()) 
for i in range(1,n+1):
    for j in range(1,m+1):
        dp1[i][j]=a[i-1][j-1]+max(dp1[i-1][j],dp1[i][j-1])

for i in range(n,0,-1):
    for j in range(1,m+1):

        dp2[i][j]=a[i-1][j-1]+max(dp2[i+1][j],dp2[i][j-1])
for i in range(1,n+1):
    for j in range(m,0,-1):
        
        dp3[i][j]=a[i-1][j-1]+max(dp3[i-1][j],dp3[i][j+1])
for i in range(n,0,-1):
    for j in range(m,0,-1):
        dp4[i][j]=a[i-1][j-1]+max(dp4[i+1][j],dp4[i][j+1])
for i in range(2,n):
    for j in range(2,m):
        tm=dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j]
        pm=dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1]
        
        
        ans=max(ans,max(tm,pm))
'''
for i in range(n+2):
    print(*dp1[i])
print('--------------------------')
for i in range(n+2):
    print(*dp2[i])
print('--------------------------')
for i in range(n+2):
    print(*dp3[i])
print('--------------------------')
for i in range(n+2):
    print(*dp4[i])
print('--------------------------')
'''
print(ans)

