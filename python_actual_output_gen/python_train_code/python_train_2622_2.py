n,m,d=map(int,input().split())
b=[[int(i) for i in input().split()] for j in range(n)]
a=[]
for i in range(n):
    for j in range(m):
        a.append(b[i][j])
a.sort()
f=1
l=n*m
for i in range(l-1):
    if a[i]%d!=a[i+1]%d:
        f=0
        break
if f==0:
    print(-1)
else:
    k=n//2
    s=0
    for i in range(l):
        s+=(abs(a[k]-a[i]))//d
    print(s)