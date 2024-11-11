import sys
inf = float("inf")

#from collections import deque, Counter, OrderedDict,defaultdict
#from heapq import nsmallest, nlargest, heapify,heappop ,heappush, heapreplace
from math import ceil,floor,log,log2,sqrt,factorial,pow,pi,gcd
#from bisect import bisect_left,bisect_right

def powerMod(x, y):
    res = 1
    while y > 0:
        if y & 1:
            res = (res * x)
        y = y >> 1
        x = (x * x)
    return res

abc='abcdefghijklmnopqrstuvwxyz'
abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod,MOD=1000000007,998244353
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

n=int(input())
s=list(input())
z=[]
for i in s:
    if i=='2':
        z.append('2')
    elif i=='3':
        z.append('3')
    elif i=='4':
        z.extend(['3','2','2'])
    elif i=='5':
        z.append('5')
    elif i=='6':
        z.extend(['5','3'])
    elif i=='7':
        z.append('7')
    elif i=='8':
        z.extend(['7','2','2','2'])
    elif i=='9':
        z.extend(['7','3','3','2'])
z.sort(reverse=True)
print(''.join(z))