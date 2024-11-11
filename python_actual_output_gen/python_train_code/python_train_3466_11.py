s=input()
ans=0
n=len(s)
a=[0]*(n+1)
b=[0]*(n+1)
for i in range(n):
    if s[i]=='a':
        a[i+1]=a[i]+1
        b[i+1]=b[i]
    elif s[i]=='b':
        a[i+1]=a[i]
        b[i+1]=b[i]+1
for j in range(1,n+1):
    for i in range(1,j):
        ans=max(ans,a[n]-a[j]+b[j]-b[i]+a[i])
print(ans)
        