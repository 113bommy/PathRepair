from math import gcd,ceil
from collections import Counter,deque
from heapq import heappush,heappop,heapify

def rl():
    return list(map(int,input().split()))
def arp(arr):
    return ' '.join([str(i) for i in arr])
for _ in range(int(input())):
    # n = int(input())
    n,m,a,b=rl()
    if(n*a!=m*b):
        print("NO")
    else:
        s = '1'*a + '0'*(m-a)
        print("YES")
        for i in range(m):
            print(s)
            s = s[1:] + s[:1]
    