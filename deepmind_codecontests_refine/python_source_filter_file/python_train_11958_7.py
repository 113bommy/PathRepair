import sys
sys.setrecursionlimit(10**6)
n,m=map(int,input().split())
a=[[]for i in range(n+m)]
for i in range(n):
    s=list(map(int,input().split()))
    for j in s[1:]:
        a[i].append(j)
        a[n+j-1].append(i)
t=[False]*(n+m)
def g(x):
    t[x]=True
    for i in a[x]:
            if not t[i]:
                g(i)
g(0)
if all(t[:n]):
    print("YES")
else:
    print("NO")
