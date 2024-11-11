import math as mt 
import sys,string,bisect
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
d=defaultdict(int)
f=defaultdict(int)
def check(n):
    n=list(set(list(str(n))))
    if(len(n)==1):
        return True
    n.sort()
    if(n[0]=='0'):
        if(len(n)<=2):
            return True
        else:
            return False
    else:
        return False


n=I()
l=L()
if(n==1):
    print("NO")
    
elif(sum(l)%2==1):
    print("NO")
else:
    for i in l:
        d[i]+=1
        
    s=sum(l)//2
    p=0
    for i in range(n):
        if(s>p):
            if(d[s-p]>0):
                print("YES")
                exit()
            else:
                p+=l[i]
                f[l[i]]+=1
                d[l[i]]-=1
        elif(s==p):
                print("YES")
                exit()
        else:
            if(l[p-s]>0):
                print("YES")
                exit()
            else:
                p+=l[i]
                f[l[i]]-=1
    print("NO")
