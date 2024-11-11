import sys     
import math as mt
input=sys.stdin.readline
t=int(input())
#t=1  
for _ in range(t):
    #n=int(input())
    #n,m=map(int,input().split())
    #x,k,y=map(int,input().split())
    #l=list(map(int,input().split()))
    x=input()
    y=input()
    ind=1
    ind1=0
    for i in range(len(y)-1,-1,-1):
        if y[i]=='1':
            break
        ind+=1
    ch=0  
    ch1=-1
    for i in range(len(x)-1-ind+1,-1,-1):
        if x[i]=='1':   
            ch1=1
            break
        ch+=1
    
    if ind==len(y):
        print(0)
    else:
        if ch1==-1:
            print(0)
        else:
            print(ch)
        