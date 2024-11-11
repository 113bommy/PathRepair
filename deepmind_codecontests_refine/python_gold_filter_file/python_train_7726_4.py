import sys
input=sys.stdin.readline
from math import *
t=int(input())
while t>0:
    t-=1
    n,m=map(int,input().split())
    p=[0 for i in range(70)]
    a=[int(x) for x in input().split()]
    if sum(a)<n:
        print(-1)
        continue
    for i in a:
        p[int(log(i,2))]+=1
    a=list(bin(n))[2:][::-1]
    d=0
    flag=0
    #print(a)
    #print(p)
    for i in range(len(a)):
        if a[i]=='1':
            c=2**i
            for j in range(i,-1,-1):
                if p[j]*(2**j)>=c:
                    p[j]-=(i-j+1)
                    c=0
                    break
                else:
                    c-=(p[j]*(2**j))
                    p[j]=0
                    #print(c)
            #print("c after 1st ",c)        
            if c>0:
               c=2**i
               for j in range(i+1,70):
                    if p[j]>0:
                        p[j]-=1
                        d+=(j-i)
                        for k in range(i,j):
                           p[k]+=1
                        c=0
                        break
            #print("c=",c,p)        
            if c!=0:
                flag=1
                break
    print(d if flag==0 else -1)        
                    
                