n=int(input())
ans=0
for i in range(1,n+1):
    d=n/(2*i)
    ans+=i*d*(2*d+1)
print(ans)