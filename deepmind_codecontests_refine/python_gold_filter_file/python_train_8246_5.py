from collections import Counter
from collections import defaultdict as dfd
from bisect import bisect, bisect_left
from math import sqrt, gcd, ceil, factorial
from heapq import heapify, heappush, heappop


MOD = 10**9 + 7
inf = float("inf")
ans_ = []

def nin():return int(input())
def ninf():return int(file.readline())

def st():return (input().strip())
def stf():return (file.readline().strip())

def read(): return list(map(int, input().strip().split()))
def readf():return list(map(int, file.readline().strip().split()))


def chk(a, b):
    return(ord(b)+1 == ord(a))
            


# file = open("input.txt", "r")
def solve():
#     for _ in range(ninf()):
    n = nin(); s = st()
    # print(s)
    ans = 0
    for i in reversed(list("abcdefghijklmnopqrstuvwxy")):
        left, right = chr(ord(i)+1)+i, i+chr(ord(i)+1)
        while len(s) > 1 and left in s:
            ind = s.index(left)
            s = list(s)
            s.pop(ind)
            s = "".join(s)
            ans += 1
        while len(s) > 1 and right in s:
            ind = s.index(right)
            s = list(s)
            s.pop(ind+1)
            s = "".join(s)
            ans += 1
    ans_.append(ans)
                
                
        
    
        
# file.close()
solve()

for i in ans_:print(i)
    