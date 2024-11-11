from collections import Counter,defaultdict,deque
#import heapq as hq
#import itertools
#from operator import itemgetter
#from itertools import count, islice
#from functools import reduce
#alph = 'abcdefghijklmnopqrstuvwxyz'
#from math import factorial as fact
#a,b = [int(x) for x in input().split()]
#sarr = [x for x in input().strip().split()]
#import math
import sys
input=sys.stdin.readline
#sys.setrecursionlimit(2**30)

def solve():
    n = int(input())
    mem=[2]
    s = 4
    res = 0
    c = 1
    while mem[-1]<=n:
        mem.append(mem[-1]+s+c)
        s+=2
        c+=1
    #print(mem)
    for el in reversed(mem):
        if n>=el:
            n-=el
            res+=1
    print(res)
            
    
 
    
 
                
            
                
 
tt = int(input())
for test in range(tt):
    solve()
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#
