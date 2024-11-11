import sys
input = sys.stdin.readline
from math import sqrt

a,b=map(int,input().split())
x=a+b

A=[]
for i in range(1,int(sqrt(a))+1):
    if a%i==0:
        A.append(i)

B=[]
for i in range(1,int(sqrt(b))+1):
    if b%i==0:
        B.append(i)


for i in range(int(sqrt(x))+1,0,-1):
    if x%i==0:
        y=x//i
        flag=0
        for m in A:
            if m<=i and a//m<=y:
                flag=1
                break

        for m in B:
            if m<=i and b//m<=y:
                flag=1
                break

        if flag:
            print(i*2+y*2)
            break
            

        
