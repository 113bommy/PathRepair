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
def prime(x):
        p=ceil(x**.5)+1
        for i in range(2,p):
            if x%i==0:
                return 0
        return 1

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

color4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]

"""

###########################---START-CODING---###############################################

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
def prime(x):
        p=ceil(x**.5)+1
        for i in range(2,p):
            if x%i==0:
                return 0
        return 1

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

color4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]

"""

###########################---START-CODING---###############################################

n=int(z())
l=[0]*n
i=3
j=0
if n>1000:
    while True:
        print(30000+j,end=' ')
        j+=1
        if j==n:
            exit()
    
while j!=(n):
    if prime(i)==1:
        l[j]=i
        j+=1
    i+=1

print(*l)
    
