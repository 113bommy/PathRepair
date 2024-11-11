import math
import random
import string
from collections import Counter
 
for _ in range(int(input())):	
    k="a"*50
    n=int(input())
    a=list(map(int,input().split()))
    l=[k]
    c=1
    for i in a:
        s=""
        c=c+1
        s=k[:i]+chr(98+((c)%25))*(50-i)
        k=s
        l.append(s)
    for i in l:
        print(i)