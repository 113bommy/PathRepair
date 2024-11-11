from sys import maxsize, stdout, stdin,stderr
mod = int(1e9 + 7)
 
def I(): return int(stdin.readline())
def lint(): return [int(x) for x in stdin.readline().split()]
def S(): return input().strip()
def grid(r, c): return [lint() for i in range(r)]
from collections import defaultdict, Counter
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
    return a  / gcd(a, b) * b
 
def check_prime(n):
    for i in range(2, int(n ** (1 / 2)) + 1):
        if not n % i:
            return False
    return True
def Bs(a, x):
    i=0
    j=0
    left = 0
    right = len(a)
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
    n=lint()
    
    return n

d = defaultdict(lambda:[])
 
def dfs(i,p):
    
    a,tmp=0,0
    for j in d[i]:
        if j!=p:
            a+=1
            tmp+=dfs(j,i)
    
    if a==0:
        return 0
    
    return tmp/a + 1 


        

n = I()
s=[I() for _ in range(n)]
ans=1
tot=s[0]
for i in range(1,n):
    tot+=s[i]
    ans*=nCr(tot-1,s[i]-1)
print(ans%mod)
    
