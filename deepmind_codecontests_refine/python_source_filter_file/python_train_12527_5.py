import math as mt 
import sys,string
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
s=input().strip()
if(s.count('.')==0):
    print("NO")
else:
    s=s.split()
    if(len(s[0])>8 or len(s)<1):
        print("NO")
    elif(len(s[-1])>3 or len(s[-1])<1):
        print("NO")
    else:
        x=[]
        #print(s)
        for i in range(1,len(s)-1):
            if(len(s[i])<2 or len(s[i])>11):
                print("NO")
                exit()
            else:
                x.append(str(s[i-1]+'.'+s[i][:min(3,len(s[i])-1)]))
                s[i]=s[i][min(3,len(s[i])-1)::]
        x.append(s[-2]+'.'+s[-1])
        print("YES")
        for i in x:
            print(i)
        
