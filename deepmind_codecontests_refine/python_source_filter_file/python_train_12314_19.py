import sys, os.path
from collections import*
from heapq import *
from copy import*
import math
mod=10**9+7
read = lambda: map(int, input().split())
inf=float('inf')
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")  

for t in range(int(input())):
    n=int(input())
    b=list(read())
    d=Counter(b)
    
    flag=0
    for i in d:
        if(d[i]==2):
            flag=1
            break
    if(flag==1):
        print('YES')
    else:
        print('NO')

    


    

    

    