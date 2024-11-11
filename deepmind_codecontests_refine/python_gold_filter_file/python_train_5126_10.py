import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log2, ceil
from collections import defaultdict
from bisect import bisect_left as bl, bisect_right as br
from collections import Counter
from collections import deque
 
ip = lambda : int(stdin.readline())
inp = lambda: map(int,stdin.readline().split())
ips = lambda: stdin.readline().rstrip()

t = ip()
for _ in range(t):
    n,x = inp()
    arr = list(inp())
    arr = sorted(list(set(arr)))
    ch = [False]*202
    for i in arr:
        ch[i] = True
    arr = list(ch)
    for i in range(1,202):
        if arr[i]:
            pass
        else:
            if x == 0:
                i -= 1
                break
            arr[i] = True
            x -= 1
    print(i)
            
            
            
            
        
