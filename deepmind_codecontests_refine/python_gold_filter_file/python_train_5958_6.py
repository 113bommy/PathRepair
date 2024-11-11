from math import ceil, floor
from collections import defaultdict 
 
for _ in range(int(input())):
    
    n,g,b = map(int,input().split())
    
    if ceil(n/2)<=g:
        print(n)
    else:
        x = ceil(n/2)
        cnt = x//g 
                
        if x%g:
            u = x%g 
            ans = cnt*(g+b) + u
            
        else:
            ans = cnt*(g+b) - b
        
        print(max(n,ans))