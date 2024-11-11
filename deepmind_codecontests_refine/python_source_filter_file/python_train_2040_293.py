#_________________ Mukul Mohan Varshney _______________#
 
#Template
import sys
import os
import math
import copy
from math import gcd
from bisect import bisect
from io import BytesIO, IOBase
from math import sqrt,floor,factorial,gcd,log,ceil
from collections import deque,Counter,defaultdict
from itertools import permutations, combinations
import itertools
 
#define function 
def Int(): return int(sys.stdin.readline())
def Mint(): return map(int,sys.stdin.readline().split())
def Lstr(): return list(sys.stdin.readline().strip())
def Str(): return sys.stdin.readline().strip()
def Mstr(): return map(str,sys.stdin.readline().strip().split())
def List(): return list(map(int,sys.stdin.readline().split()))
def Hash(): return dict()
def Mod(): return 1000000007
def Ncr(n,r,p): return ((fact[n])*((ifact[r]*ifact[n-r])%p))%p
def Most_frequent(list): return max(set(list), key = list.count)
def Mat2x2(n): return [List() for _ in range(n)]
def Lcm(x,y):  return (x*y)//gcd(x,y)
def dtob(n): return bin(n).replace("0b","")
def btod(n): return int(n,2) 
def common(l1, l2): 
    return set(l1).intersection(l2) 

# Driver Code     
def solution():
     #for _ in range(Int()):
          n=Int()
          print(n//2-1)          

#Call the solve function          
if __name__ == "__main__":
     solution()  
