n,m=map(int,input().split())
a=list(map(int,input().split()))
l=[0]*(m+1)
v=[0]*100001
f=[0]*(n+1)
b=int()
for i in range(m):
    l[i]=int(input())
for i in range(n-1,-1,-1):
    if v[a[i]]==0:
        v[a[i]]+=1
        b+=1
        f[i]=b
    else:
        f[i]=b
for i in range(m):
    print(f[i])
