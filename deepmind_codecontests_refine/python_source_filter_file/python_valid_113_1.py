from collections import deque, Counter
from collections import defaultdict as dfd
from bisect import bisect, bisect_left
from math import sqrt, gcd, ceil, factorial, log2
from heapq import heapify, heappush, heappop

# import sys
# sys.setrecursionlimit(10**7) 

MOD = 10**9 + 7
inf = float("inf")
ans_ = []

def nin():return int(input())
def ninf():return int(file.readline())

def st():return (input().strip())
def stf():return (file.readline().strip())

def read(): return list(map(int, input().strip().split()))
def readf():return list(map(int, file.readline().strip().split()))

def readfl(): return list(map(float, input().strip().split()))
def readffl():return list(map(float, file.readline().strip().split()))


# file = open("input.txt", "r")
def solve():
#     for _ in range(ninf()):
    n = nin(); arr = read()
    m = nin()
    arr.sort()
    s = sum(arr)

    for i in range(m):
        x, y = read()
        ind = bisect(arr, x)
        ind2 = bisect(arr, x-1)
        if (ind != 0 and arr[ind-1] == x) or ind == n:ind -= 1
        if (ind2 != 0 and arr[ind2-1] == x-1) or ind2 == n:ind2 -= 1

        a = max(0, x-arr[ind]) + max(0, y - (s-arr[ind]))
        b = max(0, x-arr[ind2]) + max(0, y - (s-arr[ind2]))
        
#         print(arr, a, b, ind, ind2, x, y)

        ans_.append(min(a,b))
                
            
        
solve()

for i in ans_:
    print(i)
    
    