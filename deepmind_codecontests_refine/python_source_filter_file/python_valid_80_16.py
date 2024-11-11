from collections import defaultdict as dd
import math
import sys
input=sys.stdin.readline
def nn():
    return int(input())
 
def li():
    return list(input())
 
def mi():
    return map(int, input().split())
 
def lm():
    return list(map(int, input().split()))
 
 
 
def solve():
    k = nn()
    n = input()
    n = list(str(n))[:-1]
    n = [int(dig) for dig in n]
    #print(n)
    for i in range(k//2):
        if n[i]==0:
            print(i+1,k,i+2,k)
            return
    for j in range(k//2, k):
        if n[j]==0:
            print(1, j, 1, j+1)
            return
    print(1,k-1, 2, k)
    return 
        
    
    
q=nn()
for _ in range(q):
    solve()