# cook your dish here
import sys
def get_inpL(): return list(map(int, sys.stdin.readline().strip().split()))
def get_inp(): return map(int, sys.stdin.readline().strip().split())
t=1
for _ in range(t):
    v=int(input())
    a=get_inpL()
    m=int(1e6)
    ind=0
    for i in range(len(a)):
        if(a[i]<=m):
            m=a[i]
            ind=i
    count=int(v/m)
    rem=int(v%m)
    if(count==0):
        print(-1)
    for i in range(len(a)-1,-1,-1):
        while(count>0 and (a[i]-a[ind])<=rem):
            print((i+1),end="")
            count=count-1
            rem=rem-(a[i]-a[ind])
            