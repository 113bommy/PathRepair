import sys
from sys import stdin,stdout
import math
import random
import heapq
from collections import Counter
from functools import lru_cache
#@lru_cache(maxsize=None) #for optimizing the execution time of callable objects/functions(placed above callable functions)
try:
    for _ in range(int(input())):
        n,k=map(int,input().split())
        arr=[int(i) for i in input().split()]
        arr.sort()
        for i in range(n-1,-1,-1):
            if arr[i]!=0 and k>0:
                arr[n-1]+=arr[i]
                k-=1
                if k==0:
                    break
        print(arr[n-1])
        
        
except EOFError as e:
    print(e)
