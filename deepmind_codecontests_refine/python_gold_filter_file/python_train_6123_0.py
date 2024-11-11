import sys
sys.setrecursionlimit(10**6)
n=int(input())
s=[[]for i in range(n+1)]
m=10**9+7
for i in range(n-1):
    x,y=map(int,input().split())
    s[x].append(y)
    s[y].append(x)
t=[[0,0]for i in range(n+1)]
def f(a,b):
    t[a][0]=t[a][1]=1
    for i in s[a]:
        if i!=b:
            f(i,a)
            t[a][0]*=t[i][0]+t[i][1]
            t[a][1]*=t[i][0]
f(1,0)
print(sum(t[1])%m)