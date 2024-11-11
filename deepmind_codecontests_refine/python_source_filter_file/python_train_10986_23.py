"""
    Template written to be used by Python Programmers.
    Use at your own risk!!!!
    Owned by adi0311(rating - 5 star at CodeChef and Specialist at Codeforces).
"""
import sys
import heapq
from math import *
from collections import defaultdict as dd  # defaultdict(<datatype>) Free of KeyError.
from collections import deque  # deque(list) append(), appendleft(), pop(), popleft() - O(1)
from collections import Counter as c  # Counter(list)  return a dict with {key: count}
from itertools import combinations as comb
from bisect import bisect_left as bl, bisect_right as br, bisect
# sys.setrecursionlimit(2*pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(var): sys.stdout.write(var)
def l(): return list(map(int, data().split()))
def sl(): return list(map(str, data().split()))
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [[val for i in range(n)] for j in range(m)]

def left(arr, i):
    res = 1
    j = i+1
    while j < n and arr[j] <= arr[j-1]:
        res += 1
        j += 1
    return res
def right(arr, i):
    res = 1
    j = i-1
    while j > 0 and arr[j] <= arr[j+1]:
        res += 1
        j -= 1
    return res
n = int(data())
arr = l()
answer = 0
for i in range(n):
    if i == 0:
        res = left(arr, i)
    elif i == n-1:
        res = right(arr, i)
    else:
        res = left(arr, i)+right(arr, i)-1
    answer = max(answer, res)
print(answer)
