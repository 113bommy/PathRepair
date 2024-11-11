import sys
import itertools
import math

def first(i,a,b):
    if i%2==0: return [a,b,i]
    else: return [b,a,i]

def chk(a,b):
    if m==l:
        for i in range(m-1):
            if a[i][0]>b[i][0] or b[i][0]>a[i+1][0]:
                return 0
        if a[m-1][0]>b[m-1][0]: return 0
            
    else:
        for i in range(l):
            if a[i][0]>b[i][0] or b[i][0]>a[i+1][0]:
                return 0

    return 1

def cal(a,b):
    w=[]
    if m==l:
        for i in range(l):
            w+=[a[i][1],b[i][1]]
    else:
        for i in range(l):
            w+=[a[i][1],b[i][1]]
        w.append(a[m-1][1])
    return w
        


n=int(input())
m,l=n-n//2,n//2
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if n==1:
    print(0)
    sys.exit()

x=[first(i,a[i],b[i]) for i in range(n)]

p=[i for i in range(n)]
ans=1000000

for q in itertools.combinations(p,m):
    tmpa,tmpb=[],[]
    for i in range(n):
        if i in q: tmpa.append([ x[i][0],x[i][2] ])
        else: tmpb.append([x[i][1],x[i][2]])
    tmpa.sort()
    tmpb.sort()


    if chk(tmpa,tmpb)==1:
        t=cal(tmpa,tmpb)
        tans=0
        for i in range(n):
            for j in range(i):
                if t[j]>t[i]: tans+=1
        ans=min(ans,tans)

print(ans if ans<=n*(n-1)/2 else -1)