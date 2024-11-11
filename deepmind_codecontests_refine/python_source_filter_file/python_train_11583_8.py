
#from collections import Counter,defaultdict,deque
#from heapq import *
#from itertools import *
#from operator import itemgetter
#from itertools import count, islice
#from functools import reduce
#alph = 'abcdefghijklmnopqrstuvwxyz'
#dirs = [[1,0],[0,1],[-1,0],[0,-1]]
#from math import factorial as fact
#a,b = [int(x) for x in input().split()]
#sarr = [x for x in input().strip().split()]
#import math
#from math import *

import sys
input=sys.stdin.readline
#sys.setrecursionlimit(2**30)
#MOD = 10**9+7

def solve():

    n,k = [int(x) for x in input().split()]
    s = input().strip()
    def calc(l):
        if l<=0: return 0
        return (l-1)//(k+1)+1
    a = n-len(s.lstrip('0'))
    if a==n:
        print(calc(n))
        return
    b = n-len(s.rstrip('0'))
    arr = s.split('1')[1:n-1]
    ans = calc(a-k)+calc(b-k)
    #print(arr)
    for el in arr:
        ans+=calc(len(el)-2*k)
    print(ans)
    
    
tt = int(input())
for test in range(tt):
    solve()
 
 


 
 
 
 
 
 
 
 
 
 
 
 
#
