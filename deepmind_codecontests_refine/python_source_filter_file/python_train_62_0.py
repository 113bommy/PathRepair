n,d=map(int,input().split())
a=list(map(int,input().split()))
f=True
b=[a[0]]
for i in range(1,n):
    b.append(b[i-1]+a[i])
if max(b)>d:
    f=False
        
h=[0]*n
h[n-1]=b[n-1]
for i in range(n-2,-1,-1):
    h[i]=max(b[i],h[i+1])
x,k=0,0
for i in range(n):
    if a[i]==0 and b[i]+x<0:
        k+=1
        x+=d-h[i]
        if b[i]+x<0:
            f=False
            break
if f:
    print(k)
else:
    print(-1)