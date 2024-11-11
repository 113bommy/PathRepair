#Consistency is the key.
#code by: amritanshu
from sys import stdin,stdout
import math
from collections import deque
input=stdin.readline
def print(*args,end='\n'):
    s=[]
    for i in args:
        s.append(str(i)+' ')
    s=''.join(s)
    stdout.write(s+end)


def solve():
    n=int(input())
    l=list(map(int,input().split()))
    if len(set(l))==n:
        print(n)
    else:
        print(1)
    
    
                                    
tt=1
tt=int(input())
for __ in range(tt):
    solve()
