n,a,b=map(int, input().split())
x=list(map(int, input().split()))
ans=[0]*n;
for i in range(n) : 
    ans[i]=int(x[i]*a%b/a)
print(*ans)