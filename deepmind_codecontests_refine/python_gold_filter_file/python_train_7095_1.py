n,a,x,b,y = list(map(int,input().split()))
if a<=x:
    c=list(range(a,x+1))
else:
    c=list(range(a,n+1))+list(range(1,x+1))

if b>=y:
    d=list(range(y,b+1))
    d.reverse()
else:
    e=list(range(1,b+1))
    f=list(range(y,n+1))
    e.reverse()
    f.reverse()
    d=e+f

n = min(len(c),len(d))
l=0
for i in range(n):
    if c[i]==d[i]:
        l=l+1
        break
if l==1:
    print("YES")
else:
    print("NO")