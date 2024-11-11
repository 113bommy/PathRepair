import sys
from sys import stdout

input = lambda: sys.stdin.readline().strip()
P = lambda: list(map(int, input().split()))
from math import factorial as f, gcd
from collections import deque, defaultdict as dd, Counter as C
from heapq import heapify, heappop, heappush, heappushpop, heapreplace, merge
from random import randint, choice, sample
import time
mod = 10**9+7
a = ord('a')


start = time.time()
def fast_exp(x, exp):
    ans = 1
    base = x
    while exp:
        if exp & 1:
            ans *= base
        base *= base
        base %= mod
        ans %= mod
        exp >>= 1
    return ans

def countBits(n):
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count

def submasks(n):
    #this is cool
    #https://cp-algorithms.com/algebra/all-submasks.html
    org = n
    while n:
        yield n
        n = (n-1) & org

def d2k(d, k):
    mapping = "0123456789ABCDEF"
    res = []
    while d != 0:
        res.append(d%k)
        d //= k
    return res[::-1]


def solve():
    n, a, b = P()
    if a == 1:
        print("Yes" if (n-1) % b == 0 else "No") 
    
    
    else:
        curr = a
        while curr <= n:
            if (n-curr) % b == 0:
                print('Yes')
                return
            curr *= a
        print('No')

    
    # arr = [0] * 101
    # arr[1] = 1
    # for i in range(2, 101):
    #     if (i%a==0 and arr[i//a]) or (i >= b and arr[i-b]):
    #         arr[i] = 1
    # for i, x in enumerate(arr):
    #     if x:
    #         print(i)



    






tc = int(input())
for t in range(1, tc+1):
    solve()

# solve()
# print(time.time()-start)


