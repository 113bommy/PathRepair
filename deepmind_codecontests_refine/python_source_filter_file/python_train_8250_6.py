import math
import sys
#input=sys.stdin.readline
t=int(input())
#t=1
for _ in range(t):
    n=int(input())
    #n,m=map(int,input().split())
    #l1=list(map(int,input().split()))
    a=input()
    a+='0'
    b=input()
    b+='0'
    ans=[]
    ans1=[]
    for i in range(n):
        if a[i]=='1' and a[i+1]=='0' :
            ans.append(i+1)
        if a[i]=='0' and a[i+1]=='1':
            ans.append(i+1)
        if b[i]=='1' and b[i+1]=='0' :
            ans1.append(i+1)
        if b[i]=='0' and b[i+1]=='1':
            ans1.append(i+1)    
    if len(ans)+len(ans1)==0:
        print(0)
    else:    
        print(len(ans)+len(ans1),*ans,*ans1)        