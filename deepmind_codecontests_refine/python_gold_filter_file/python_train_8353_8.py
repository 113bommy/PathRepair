#A,B,C,D = map(int,input().split())
import math
from fractions import gcd
t = int(input())
for i in range(t):
    a,b = list(map(int,input().split()))
    D = list(input())
    
    counts = []
    for el in set(D):
        counts.append(D.count(el))
        
    counts.sort(reverse=True)
    
    if True:#a>=b:
       # print(counts)
        
        maxx = 0
        #for j in range(len(counts)):
        #    maxx = max(maxx, (j+1) * counts[j])
            
        #print(maxx)
        for j in range(1,b+1):
            if b%j==0:
                for k in range(1,max(counts)+1):
                    tot = 0
                
                    for el in range(min(j,len(counts))):
                        tot += counts[el] // k
                        
                    if tot >= j:
                        maxx = max(maxx, j*k)
            
    else:
        for j in range(1,a+1):
            if b % j == 0:
                maxx = j
    print(maxx)