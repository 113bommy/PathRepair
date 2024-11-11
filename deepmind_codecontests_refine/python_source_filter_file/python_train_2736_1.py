from math import *
from bisect import *
from collections import *
from random import *
from decimal import *
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=inp()
while(t):
    t-=1
    n,m=ma()
    r=[]
    for i in range(n):
        a=st()
        a=list(a)
        r.append(a)
    res=[]
    for i in range(n-1):
        for j in range(m-1):
            ll=0
            one=[]
            zer=[]
            if(r[i][j]=='1'):
                ll+=1
                one.append([i+1,j+1])
                r[i][j]='0'
            else:
                zer.append([i+1,j+1])
            if(r[i+1][j]=='1'):
                ll+=1
                one.append([i+2,j+1])
                r[i+1][j]='0'
            else:
                zer.append([i+2,j+1])
            if(r[i][j+1]=='1'):
                ll+=1
                one.append([i+1,j+2])
                r[i][j+1]='0'
            else:
                zer.append([i+1,j+2])
            if(r[i+1][j+1]=='1'):
                ll+=1
                one.append([i+2,j+2])
                r[i+1][j+1]='0'
            else:
                zer.append([i+2,j+2])
            if(ll==0):
                continue
            if(ll==3):
                res.append(one[0])
                res.append(one[1])
                res.append(one[2])
                continue
            if(ll==2):
                res.append(zer[0])
                res.append(zer[1])
                res.append(one[0])
                res.append(zer[0])
                res.append(zer[1])
                res.append(one[1])
                continue
            if(ll==1):
                res.append(zer[0])
                res.append(zer[1])
                res.append(one[0])
                res.append(zer[2])
                res.append(zer[0])
                res.append(one[0])
                res.append(zer[2])
                res.append(zer[0])
                res.append(one[0])
                continue
            if(ll==4):
                res.append(one[0])
                res.append(one[1])
                res.append(one[2])
                res.append(one[0])
                res.append(one[1])
                res.append(one[3])
                res.append(one[2])
                res.append(one[3])
                res.append(one[1])
                res.append(one[0])
                res.append(one[2])
                res.append(one[3])
                continue
    print(len(res)//3)
    i=0
    while(i<len(res)):
        print(*res[i],*res[i+1],*res[i+2])
        i+=3
    
                
            
            
            
        
        
