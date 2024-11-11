n,k,m,d = map(int,input().split())
mi = n//(k*d)
z=n

if(n%(k*d) != 0):
    mi+=1
t=n//(k*mi)
z-=k*mi*t
if(z>=mi):
    t+=1
d = min(d, t)
ans=0
for i in range(1,d+1):
    x = n //((i-1)*k+1)
    for j in range(x, x+1):
        if(j*(i-1)*k>=n):
            continue
        if j*i*k<n and n-j*i*k >= x:
            continue
        if j>=mi and j <= m:
            ans = max(ans, i*j)
        if(mi*(i-1)*k>=n):
            continue
        if mi*i*k<n and n-j*i*k >= mi:
            continue
        ans = max(ans,i*mi)

        if(m*(i-1)*k>=n):
            continue
        if m*i*k<n and n-j*i*k >= m:
            continue
        ans = max(ans,i*m)
print(ans)
