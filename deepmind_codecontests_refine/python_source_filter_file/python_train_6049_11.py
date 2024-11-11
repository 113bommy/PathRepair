n,w,b = map(int,input().split())
c=[w,b]
t=list(map(int,input().split()))
if n%2==0:
    x,y=t[:n//2],t[n//2:]
else:
    x,y=t[:n//2],t[n//2+1:]
    z=t[n//2]
y=y[::-1]
s=0
f=False
for i in range(n//2):
    if x[i]!=y[i] and x[i]!=2 and y[i]!=2:
        f=True
        break
    elif x[i]==2 and y[i]!=2:
        s+=c[y[i]]
    elif y[i]==2 and x[i]!=2:
        s+=c[x[i]]
    elif x[i]==y[i]==2:
        s+=min(c)
if f:
    print(-1)
else:
    if n%2==1 and z==2:
        s+=min(c)
    print(s)