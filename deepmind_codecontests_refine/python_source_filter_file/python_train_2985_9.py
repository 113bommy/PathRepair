I=lambda:list(map(int,input().split()))
n,s,a=int(input()),I(),I()
t=3*10**9
q=[0]*n
for i in range(n-1,-1,-1):
    u=10**8
    for j in range(i-1,-1,-1):
        if s[i]>s[j]:u=min(u,a[j])
    q[i]=u
for i in range(n):
    for j in range(i+1,n):
        if s[i]<s[j]:t=min(t,a[i]+a[j]+q[i])
print(t if t<sum(a)else -1)