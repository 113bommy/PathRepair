from math import gcd,ceil,log
from collections import Counter,deque
from heapq import heappush,heappop,heapify

def rl():
    return list(map(int,input().split()))


def arp(arr):
    return ''.join(arr)


for _ in range(int(input())):
    n,k = rl()
    ans = n-n%k
    ans+=min(k//2,n%k)
    print(ans)
    