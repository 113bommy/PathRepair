import io,os,sys
import math
import random
from queue import PriorityQueue as PQ
from bisect import bisect_left as BSL
from bisect import bisect_right as BSR
from collections import OrderedDict as OD
from collections import Counter
from itertools import permutations
from decimal import Decimal as BIGFLOAT

# mod = 998244353
mod = 1000000007
# mod = 998244353 

sys.setrecursionlimit(10**6)


try:
    f = os.open("actext.txt",os.O_RDONLY)
    input = io.BytesIO(os.read(f,os.fstat(f).st_size)).readline
    
except:
    input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
    
    

 
def get_ints():
    return map(int,input().decode().split())
 
def palindrome(s):
    mid = len(s)//2
    for i in range(mid):
        if(s[i]!=s[len(s)-i-1]):
            return False
    return True
def check(i,n):
    if(0<=i<n):
        return True
    else:
        return False
    
# --------------------------------------------------------------------------

def binlifting(k):
    k = bin(k)[2:]
    ans = 4
    res = 1
    for i in k[::-1]:
        if(i=='1'):
            res*=ans
            res=res%mod
        ans = ans*ans
        ans = ans%mod

    return res%mod
            
    
    
def solve(n):
    if(n==2):
        print(6)
        return
    
    nn = (2**n)  -2
    ans = 6
    
    ans = ans*binlifting(nn)
    ans = ans%mod
    print(ans)
              
n = int(input().decode())
solve(n)

    