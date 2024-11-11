
from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
import math
from collections import *
from functools import reduce,cmp_to_key,lru_cache
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# import sys
# input = sys.stdin.readline
 
M = mod = 10**9 + 7 
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip().split()]
def st():return str(input().rstrip())[2:-1]
def val():return int(input().rstrip())
def li2():return [str(i)[2:-1] for i in input().rstrip().split()]
def li3():return [int(i) for i in st()]


n = l = 0
def check(tot):
    global l, n
    first = 0
    second = 0

    for i in range(n):
        first += l[i][tot]
        second += sum(l[i]) - l[i][tot]
    
    l.sort(key = lambda x : x[tot] - sum(x))
    # print(l, first, second)
    temp = n
    ind = 0
    while first <= second and temp:
        first -= l[ind][tot]
        second -= sum(l[ind]) - l[ind][tot]
        ind += 1
        temp -= 1
        # print(first, second, temp, tot)
    return temp



for _ in range(val()):
    n = val()
    l = [[0] * 5 for i in range(n)]

    for i in range(n):
        s = st()
        l[i][0] = s.count('a')
        l[i][1] = s.count('b')
        l[i][2] = s.count('c')
        l[i][3] = s.count('d')
        l[i][4] = s.count('e')
    

    ma = 0
    for i in range(5):
        ma = max(ma, check(i))
    print(ma)