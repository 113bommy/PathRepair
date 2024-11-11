import sys
import math
import bisect
from collections import deque
 
sys.setrecursionlimit(1000000000)
def input():
    return sys.stdin.readline().strip()
 
def iinput():
    return int(input())
 
def finput():
    return float(input())
 
def tinput():
    return input().split()
 
def rinput():
    return map(int, tinput())
 
def rlinput():
    return list(rinput())
 
def modst(a, s):
    res = 1
    while s:
        if s % 2:
            res *= a
        a *= a
        s //= 2
    return res
 

        
 
def main():
    w = ["cslnb", "sjfnb"]
    n = iinput()
    q = sorted(rlinput())
    t = 0
    for i in range(1, n):
        t += q[i] == q[i - 1]
    if t >= 2:
        return w[1]
    if t:
        for i in range(n):
            if q[i] == q[i + 1]:
                if q[i] and q[i] != q[i - 1] + 1:
                    q[i] -= 1
                    break
                else:
                    return w[0]
    return w[(sum(q) - t - n * (n - 1) // 2) & 1]
    
            
         
    
        
    
for i in range(1):
    print(main())