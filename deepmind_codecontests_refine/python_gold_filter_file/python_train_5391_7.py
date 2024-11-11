import sys
sys.setrecursionlimit(10**7)

def modinv(a,m=10**9+7):
    if a==0: return 1
    else:
        b=m
        (x, lastx) = (0, 1)
        (y, lasty) = (1, 0)
        while b != 0:
            q = a // b
            (a, b) = (b, a % b)
            (x, lastx) = (lastx - q * x, x)
            (y, lasty) = (lasty - q * y, y)
        return lastx % m

def cur(p):
    if neighbor[p]==[]: return
    for x in neighbor[p]:
        par[x]=p
        neighbor[x].remove(p)
        cur(x)
    descend[par[p]]+=descend[p]

def cur2(p):
    for x in neighbor[p]:
        ans[x]=ans[p]*descend[x]*modinv(n-descend[x])
        ans[x]%=mod
        cur2(x)

mod=10**9+7
n=int(input())
neighbor=[set()  for _ in range(n+2)]
descend=[1 for i in range(n+1)]
par=[0]+[0]*(n+1)

for _ in range(n-1):
    a,b=map(int,input().split())
    neighbor[a].add(b)
    neighbor[b].add(a)

cur(1)


ans=[1]*(n+1)
ans1=1
for i in range(1,n+1):
    ans1=ans1*i*modinv(descend[i])
    ans1%=mod
ans[1]=ans1

cur2(1)

for i in range(1,n+1):
    print(ans[i])