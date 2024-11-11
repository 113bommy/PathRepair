import math,sys
from sys import stdin, stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def solve():
    n=I()
    a=li()
    for i in range(1,n-1):
        if(a[i]>a[i-1] and a[i]>a[i+1]):
            print("YES")
            print(i-1,i,i+1)
            return 
    print("NO")
    
for _ in range(I()):
    solve()