from sys import stdin,stdout
from collections import Counter
from itertools import permutations
import bisect
import math
I=lambda: map(int,stdin.readline().split())
I1=lambda: stdin.readline()
#(a/b)%m =((a%m)*pow(b,m-2)%m)%m

for _ in range(int(I1())):
    a,b,c,d=I()
    if b>a:
        print(b)
        continue
    if d>c:
       print(-1)
       continue
    x=a-b 
    y=c-d
    z=0
    if y:  
        z=math.ceil(x/y)
    print(b + c*z)