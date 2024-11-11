z=input
mod = 10**9 + 7
from collections import *
from queue import *
from sys import *
from collections import *
from math import *
from heapq import *
from itertools import *
from bisect import *
from collections import Counter as cc
from math import factorial as f
def lcd(xnum1,xnum2):
    return (xnum1*xnum2//gcd(xnum1,xnum2))

################################################################################

"""

n=int(z())

for _ in range(int(z())):

x=int(z())

l=list(map(int,z().split()))

n=int(z())

l=sorted(list(map(int,z().split())))[::-1]

a,b=map(int,z().split())

l=set(map(int,z().split()))

led=(6,2,5,5,4,5,6,3,7,6)

vowel={'a':0,'e':0,'i':0,'o':0,'u':0}

color-4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]

"""

###########################---START-CODING---###############################################
a,b=map(int,z().split())
s=z()
s1=s.split('1')

c=0
for i in s1:
    if len(i)>=b:
        print(-1)
        exit(0)
k=0

for _ in range(a):
    for j in range(k+b,k,-1):
        try:
            if s[j]=='1':
                c+=1
                k=j
                break
        except:
            break
        
    

print(c)
            
    
    
    
    
    

    
    
    
            
        
    
        
        
    
            
