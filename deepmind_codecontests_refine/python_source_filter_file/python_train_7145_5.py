n, l = map(int, input().split())
c = list(map(int, input().split()))
v = [2**(i) for i in range(len(c))]
# Ajustar por prop
for i in range(n-1):
    c[i+1]=min(c[i+1],c[i]*2)
    
s=0
ans=10**10
for i in range(n-1,-1,-1):
    d=l//(1<<i)
    s+=d*c[i]
    l-=d<<i;
    ans=min(ans,s+(l>0)*c[i])
print(ans)