import sys, os.path
from collections import*
from copy import*
import math
mod=10**9+7
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

for t in range(int(input())):
    n=int(input())
    a=int(input())
    s=str(a)
    odd=0
    even=0
    if(n==1):
        if(a%2==0):
            print(2)
        else:
            print(1)
    else:
        if(n%2==0):
            for i in range(n):
                if(i%2==1 and int(s[i])%2==1):
                    odd+=1
            if(odd==n//2):
                print(1)
            else:
                print(2)
        else:
            for i in range(n):
                if(i%2==0 and int(s[i])%2==0):
                    even+=1
            if(even==(n//2)+1):
                print(2)
            else:
                print(1)

