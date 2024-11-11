#from math import *
#from bisect import *
#from collections import *
#from random import *
#from decimal import *"""
#from heap import *
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
t=1
gl={'a':0,'b':1,'c':2}
while(t):
    t-=1
    n,q=ma()
    s=st()
    first=[[0,0,0]]
    second=[[0,0,0]]
    third=[[0,0,0]]
    for i in range(len(s)):
        if(i%3==0):
            x=first[-1][:]
            if(s[i]=='a'):
                first.append([x[0]+1,x[1],x[2]])
            elif(s[i]=='b'):
                first.append([x[0],x[1]+1,x[2]])
            else:
                first.append([x[0],x[1],x[2]+1])
            second.append(second[-1])
            third.append(third[-1])
        elif(i%3==1):
            x=second[-1][:]
            if(s[i]=='a'):
                second.append([x[0]+1,x[1],x[2]])
            elif(s[i]=='b'):
                second.append([x[0],x[1]+1,x[2]])
            else:
                second.append([x[0],x[1],x[2]+1])
            first.append(first[-1])
            third.append(third[-1])
        else:
            x=third[-1][:]
            if(s[i]=='a'):
                third.append([x[0]+1,x[1],x[2]])
            elif(s[i]=='b'):
                third.append([x[0],x[1]+1,x[2]])
            else:
                third.append([x[0],x[1],x[2]+1])
            first.append(first[-1])
            second.append(second[-1])
    #print(first,second,third)
    for i in range(q):
        l,r=ma()
        res=float('inf')
        a=first[r][:]
        b=first[l-1][:]
        f1=[a[0]-b[0],a[1]-b[1],a[2]-b[2]]
        a=second[r][:]
        b=second[l-1][:]
        f2=[a[0]-b[0],a[1]-b[1],a[2]-b[2]]
        a=third[r][:]
        b=third[l-1][:]
        f3=[a[0]-b[0],a[1]-b[1],a[2]-b[2]]
        #print(f1,f2,f3)
        res=min(res,f1[1]+f1[2]+f2[0]+f2[2]+f3[0]+f3[1],f1[1]+f1[2]+f2[0]+f2[1]+f3[0]+f3[2],f1[0]+f1[2]+f2[1]+f2[2]+f3[0]+f3[1],f1[0]+f1[2]+f2[0]+f2[1]+f3[1]+f3[2],f1[0]+f1[1]+f2[1]+f2[2]+f3[0]+f3[2],f1[0]+f1[1]+f2[0]+f2[2]+f3[1]+f3[2])
        print(res)
        
        
                
        
                
        
        
                
        
    
    
    
