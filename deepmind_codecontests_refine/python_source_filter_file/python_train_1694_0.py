import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# m=pow(10,9)+7
t=int(input())
for i in range(t):
    n=int(input())
    a=list(input())
    b=list(input())
    start=a[0]
    curr=a[n-1]
    c=0
    l=[]
    for j in range(n-1,0,-1):
        if a[j]!=b[j]:
            a1=[]
            # a1=a[n-1:j:-1]
            if a[0]==b[j]:
                # c+=2
                l+=[1,j+1]
                a[0]=str(int(a[0])^1)
            else:
                # c+=1
                l+=[j+1]

            for k in range(j+1):
                a1.append(str(int(a[k])^1))
            a1+=a[j+1:]
            a=a1[:]
            # print(a)
            # c+=1
            # if c&1:
            #     start=b[j]
            #     curr=a[1]^1
    if a[0]!=b[0]:
        a[0]=str(int(a[0])^1)
        l.append(1)
    # print(a)
    print(len(l),*l)