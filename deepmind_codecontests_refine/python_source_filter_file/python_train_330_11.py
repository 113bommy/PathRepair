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
    n = ip()
    arr = list(inp())
    if n <= 5:
        ans = "0 0 0"
    else:
        arr = arr[::-1]
        prev = None
        pos = -1
        if n&1 == 1:
            val = n//2+1
        else:
            val = n//2
        for i in range(n):
            if i>= val:
                if prev == arr[i]:
                    pass
                else:
                    prev = arr[i]
                    pos = i
                    break
            if prev == arr[i]:
                pass
            else:
                prev = arr[i]
        if pos == -1:
            ans = "0 0 0"
        else:
            arr = arr[pos:]
            arr = arr[::-1]
            n = len(arr)
            if len(set(arr))>= 3:
                ch = sorted(list(set(arr)),reverse = True)
                gold = ch[0]
                silver = ch[1]
                g,s,b = 0,0,0
                sdic = dd(bool)
                flag = True
                for i in range(n):
                    if arr[i] == gold:
                        g += 1
                    else:
                        if s>g:
                            flag = False
                        if flag:
                            s += 1
                            sdic[arr[i]] = True
                        else:
                            if sdic[arr[i]]:
                                s += 1
                            else:
                                b += 1
                if g>s or g>b:
                    ans = "0 0 0"
                else:
                    ans = "{} {} {}".format(g,s,b)
            else:
                ans = "0 0 0"
    out(ans)
                
        
        
            
                        
                
                    
                
                    
                
        
    
        
    
    
    
                        
            
            
    
            
            
        
            
                    
            
                    
                    
                    
                    
                    
                    
                    
    
        
    
    
    
    
    
            
        
                
        
            
        
    
    
    
            
            
        
    
            
            
        
                
                
        
    
        
        
    
    
            

        
        
        

            
            
        
            
        
        
        
            
        
    
            
        
                
        
        
            
            
    
                
        
                
            
            
        
    
        
    
                
        
    
    
    
    
    
    
            

    
            
            
            
        
    

            
        
