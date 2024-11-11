import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log2, ceil
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from bisect import insort
from collections import Counter
from collections import deque
from heapq import heappush,heappop,heapify
from itertools import permutations,combinations
from itertools import accumulate as ac
from random import randint as ri
mod = int(1e9)+7
 
 
ip = lambda : int(stdin.readline())
inp = lambda: map(int,stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x : stdout.write(str(x)+"\n")


t = 1
for _ in range(t):
    n = ip()
    arr = []
    for i in range(n):
        a,b = inp()
        arr.append([b,a])
    arr.sort()
    nn = len(arr)
    arr = deque(arr)
    ans = 0
    item = 0
    st = 0
    end = 0
    while nn != 0:
        if nn == 1:
            ele = arr[0]
            b,a = ele
            
            if item>= b:
                ans += a
                arr.pop()
                nn -= 1
            else:
                diff = b - item
                if a>= diff:
                    ans += diff*2
                    item += diff
                    a -= diff
                    arr[0] = [b,a]
                else:
                    ans += diff*2
                    item += diff
                    arr.pop()
                    nn -= 1

                    
                
        else:
            small = arr[0]
            big = arr[-1]
            b_small,a_small = small
            b_big , a_big = big

            if item>= b_small:
                ans += a_small
                item += a_small
                arr.popleft()
                nn -= 1
            else:
                diff = b_small-item
                if a_big >= diff:
                    a_big -= diff
                    item += diff
                    ans += diff*2
                    arr[-1] = [b_big,a_big]
                else:
                    item += a_big
                    ans += a_big*2
                    arr.pop()
                    nn -= 1
        
    print(ans)
                    
        
    
    
            
            
    
            
