from sys import stdin,stdout
import math
##input=stdin.readline
##def print(x='',end='\n'):
##    stdout.write(str(x)+end)

def solve():
    n,k=map(int,input().split())
    l=list(input())
    lst=[]
    for i in range(n):
        if l[i]=='1':
            lst.append(i)

    if len(lst)==0:
        cnt=0
        for i in range(0,n,k+1):
            cnt+=1
        print(cnt)
        return
    cnt=0
    if lst[0]>k:
        lst.insert(0,0)
        cnt+=1
    if lst[-1]+k+1<=n-1:
        lst.append(n-1)
        cnt+=1
    
    for i in range(len(lst)-1):

        for j in range(lst[i]+k+1,lst[i+1]-1,k+1):
            cnt+=1
    print(cnt)
            
   
test=1
test=int(input())
for __ in range(test):
    solve()
