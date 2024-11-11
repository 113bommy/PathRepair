ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
#from math import log10 ,log2,ceil,factorial as f,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
#from bisect import bisect_right as br,bisect_left as bl
#from collections import Counter
from math import inf,log,ceil


for _ in range(t()):
    n=t()
    a=list(ll())

    p=[a[0]]
    se=sorted(set(range(1,n+1)).difference(set(a)))
    i=1;
    while i<n:
        if a[i]>p[i-1]:
            p.append(a[i])
            i+=1
        elif a[i]==p[i-1]:
            j=i
            while j<n and a[j]==p[i-1]:
                p.append(se.pop(0))
                j+=1
            i=j
        else:
            
            p.append(p[i-1])
            i+=1
        
    dp=[a[0]]
    print(se,p)
    if len(se)==0:
        
        for i in range(1,n):
            dp.append(max(dp[i-1],p[i]))
    #print(se)
    if dp==a and len(se)==0:
        print(*p)
    else:
        print(-1)
        
    
        
    
