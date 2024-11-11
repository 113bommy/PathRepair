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
mod = int(1e9)+7
 
 
ip = lambda : int(stdin.readline())
inp = lambda: map(int,stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x : stdout.write(str(x)+"\n")

t = ip()
for _ in range(t):
    a,b,c = inp()
    ch = [a,b,c]
    ch.sort()
    if ch[2]>=ch[0]+ch[1]+1:
        ans = "No"
    else:
        ans = "Yes"
    out(ans)
            
        
                
        
        
            
            
    
                
        
                
            
            
        
    
        
    
                
        
    
    
    
    
    
    
            

    
            
            
            
        
    

            
        
