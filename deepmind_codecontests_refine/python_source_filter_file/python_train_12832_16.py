from collections import deque
from collections import OrderedDict
import math
 
import sys
import os
import threading
import bisect
 
import operator
 
import heapq
 
 
from atexit import register
from io import BytesIO
 
#sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
#sys.stdout = BytesIO()
#register(lambda: os.write(1, sys.stdout.getvalue()))
 
 
import io
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
#sys.stdin = open("F:\PY\\test.txt", "r")
input = lambda: sys.stdin.readline().rstrip("\r\n")
#input = sys.stdin.readline

#a = [int(x) for x in input().split()]

def binary_rep(n):
    l = []
    while(n>0):
        l.append(n%2)
        n=n//2
    #l.reverse()
    return l



dM = 500

for _ in range(int(input())):
    
    n = int(input())
    ar= list(map(int, input().split()))
    dp = [0]*dM
    for i in range(n):
        dp[ar[i]]+=1
    dpAns = [0]*dM
    for i in range(dM):
        if dp[i]==0:
            continue
        for j in range(i+1, dM):
            if dp[j]==0:
                continue
            dpAns[i+j]=min(dp[i], dp[j])
    for i in range(dM):
        if dp[i]!=0:
            dpAns[i*2]+=dp[i]//2
    answer = max(dpAns)
    print(answer)
            
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    