n=int(input())
c=[0 for i in range(n+1)]
a=list(map(int,input().split()))
m,t=0,0
for i in range(0,2*n):
    if c[a[i]]==1:
        t-=1
    elif c[a[i]]==0:
        c[a[i]]+=1
        t+=1
    if t>m:
        m=t
print(m)