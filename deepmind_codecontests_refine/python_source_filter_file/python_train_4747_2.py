n,a= map(int,input().split())

if((a*(a+1)/2) > n):
    print(-1)
    exit(0)

c = a*(a+1)/2;
res = 1
q = int((n+10)**(1/2))
for i in range(1,q):
    if(n%i): continue
    if(c*i > n): continue
    i1 = n/i
    if(i1*c <= n): res = max(res,i1)
    res=max(res,i)
res = int(res)
s1 = 0
for i in range(a-1):
    print((i+1)*res,end=' ')
    s1 += (i+1)*res
print(n-s1)
