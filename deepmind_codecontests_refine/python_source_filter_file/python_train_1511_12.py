from collections import Counter,defaultdict,deque
import heapq as hq
#import itertools
#from operator import itemgetter
#from itertools import count, islice
#from functools import reduce
#alph = 'abcdefghijklmnopqrstuvwxyz'
#from math import factorial as fact
#a,b = [int(x) for x in input().split()]
#sarr = [x for x in input().strip().split()]
import math
import sys
input=sys.stdin.readline
def solve():
    n = int(input())
    
    c=[0]*(10**6+10)
    for el in (int(x) for x in input().split()):
        c[el]+=1
    res = 0
    for i in range(10**6+9):
        c[i+1]+=c[i]//2
        res+=c[i]%2
    print(res)

tt = 1#int(input())
for test in range(tt):
    solve()















#
