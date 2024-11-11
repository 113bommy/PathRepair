from math import sqrt,gcd,ceil,floor,log,factorial
from itertools import permutations,combinations
from collections import Counter, defaultdict
import collections,sys,threading
import collections,sys,threading
from bisect import *
#sys.setrecursionlimit(10**9)
#threading.stack_size(10**8)
#input=sys.stdin.readline

def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def msi(): return map(str,input().split())
def li(): return list(mi())

k=ii()
mod=10**9+7

pow1=pow(2,k,mod)-2
ans=pow(4,pow1,mod)
ans=ans*6
ans=ans%mod
print(ans)
    