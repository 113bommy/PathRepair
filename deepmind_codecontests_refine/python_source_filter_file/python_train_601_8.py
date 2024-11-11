n,m=map(int,input().split())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
a=[1]*(m+1)
for i in range(n):
    b=a[:]
    k=0
    for j in range(m):
        b[j]=(k+b[j])%(10**9+7)
        if s[i]==t[j]:
            k=(k+a[j])%(10**9+7)
    b[-1]=(k+b[-1])%(10**9+7)
    a=b[:]
print(a[-1]%(10**9+7))