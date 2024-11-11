from math import gcd,ceil
from collections import Counter,deque
from heapq import heappush,heappop,heapify

def rl():
    return list(map(int,input().split()))
def arp(arr):
    return ' '.join([str(i) for i in arr])

for _ in range(int(input())):
    n = int(input())
    arr = ''
    m = n
    while(n):
        n-=1
        ss = input()
        arr+= ss
    d = Counter(arr)
    val = list(d.values())
    f = all(m%i==0 for i in val)
    if(f):
        print("YES")
    else:
        print("NO")
    