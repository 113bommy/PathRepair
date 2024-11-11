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
    if len(set(l))==1:
        print('NO')
    else:
        print('YES')
        j=0
        for p in range(1,n):
            if l[p]!=l[0]:
                j=p
                break
        print(1,j+1)            
        for i in range(1,n):
            if i!=1 or i!=j:
                if l[i]==l[0]:
                    print(i+1,j+1)
                else:
                    print(1,i+1)
        
            
                
            
                                    
tt=1
tt=int(input())
for __ in range(tt):
    solve()
