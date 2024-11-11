import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from itertools import combinations,permutations

# input = sys.stdin.readline
flush = lambda : sys.stdout.flush
comb = lambda x , y : (factorial(x) // factorial(y)) // factorial(x - y) 


#inputs
# ip = lambda : input().rstrip()
ip = lambda : input()
ii = lambda : int(input())
r = lambda : map(int, input().split())
rr = lambda : list(r())


n = ii()
arr =rr()
k = ii()
brr = [rr() for _ in range(k)]

x = sum(arr)
for i in range(k):
    if brr[i][0] <= x <= brr[i][1]:
        print(x)
        exit()
    
    if brr[i][0]>x:
        print(brr[i][0])
        exit()
    
        
print(-1)