import sys, os.path
from collections import*
from heapq import *
from copy import*
mod=10**9+7
read = lambda: map(int, input().split())
inf=float('inf')
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")  


for t in range(int(input())):
    n=int(input())
    a=list(read())
    b=list(read())
    if(sum(a)!=sum(b)):
        print(-1)
    else:
        t=[]
        for i in range(n):
            t.append(a[i]-b[i])
        pair=[]
        for i in range(n):
            if(t[i]!=0):
                val=t[i]
                if(val>0):
                    j=i+1
                    while(val!=0):
                        if(t[j]<0):
                            t[j]+=1
                            pair.append((i+1,j+1))
                            val-=1
                        else:
                            j+=1
                else:
                    j=i+1
                    while(val!=0):
                        if(t[j]>0):
                            t[j]-=1
                            pair.append((i+1,j+1))
                            val+=1
                        else:
                            j+=1
        print(len(pair))
        for i in pair:
            print(*i)

                            




        
        
    




