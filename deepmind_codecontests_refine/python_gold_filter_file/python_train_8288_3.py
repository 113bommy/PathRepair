from sys import stdin,stdout
import math,bisect,heapq
from collections import Counter,deque,defaultdict
L = lambda:list(map(int, stdin.readline().strip().split()))
I = lambda:int(stdin.readline().strip())
S = lambda:stdin.readline().strip()
C = lambda:stdin.readline().strip().split()
def pr(a):print(" ".join(list(map(str,a))))
#_________________________________________________#

def solve():
    x = input()
    y = input()
    z = input()
    a,b = 0,0
    n = len(x)
    ind = n
    for i in range(n):
        if x[i:i+len(y)]==y:
            ind = i+len(y)
            break
    for i in range(ind,n):
        if x[i:i+len(z)]==z:
            ind = -1
    if ind==-1:
        a = 1
    x = x[::-1]
    ind = n
    for i in range(n):
        if x[i:i+len(y)]==y:
            ind = i+len(y)
            break
    for i in range(ind,n):
        if x[i:i+len(z)]==z:
            ind = -1
    if ind==-1:
        b = 1
    if a+b==2:
        print("both")
    elif a==1:
        print('forward')
    elif b==1:
        print('backward')
    else:
        print('fantasy')
        
for _ in range(1):
    solve()

