import sys
n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
v=[]
for i in range(n):
    ans=-999999999999999999
    for j in range(m):
        ans=max(ans,a[i]*b[j])
    v.append(ans)
v=sorted(v)
print(v[n-2])