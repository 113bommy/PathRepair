import sys
import math
import heapq
import collections
def inputnum():
    return(int(input()))
def inputnums():
    return(map(int,input().split()))
def inputlist():
    return(list(map(int,input().split())))
def inputstring():
    return([x for x in input()])
def inputmatrixchar(rows):
    arr2d = [[j for j in input().strip()] for i in range(rows)] 
    return arr2d
def inputmatrixint(rows):
    arr2d = []
    for _ in range(rows):
        arr2d.append([int(i) for i in input().split()])
    return arr2d
    
def smallestDivisor(n): 
    if (n % 2 == 0): 
        return 2; 
    i = 3;  
    while(i * i <= n): 
        if (n % i == 0): 
            return i; 
        i += 2; 
    return n; 
    
t=int(input())
for q in range(t):
    n = inputnum()
    a = inputlist()
    d = {2:[], 3:[], 5:[], 7:[], 11:[], 13:[], 17:[], 19:[], 23:[], 29:[], 31:[]}
    for i in range(n):
        d[smallestDivisor(a[i])].append(i)
    cur = 1
    ans = [0]*n
    for key in d:
        if len(d[key]) != 0:
            for j in range(len(d[key])):
                ans[d[key][j]] = cur
            cur += 1
    print(cur-1)
    print(*ans)