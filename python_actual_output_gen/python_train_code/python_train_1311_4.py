x,n=(map(int,input().split()))
t=round(n**0.5)
p=(t*t==n)
ans=-int(p)
for i in range(t,0,-1):
    if n/i>x:
        break
    if n%i==0:
        ans+=2
print(ans)
