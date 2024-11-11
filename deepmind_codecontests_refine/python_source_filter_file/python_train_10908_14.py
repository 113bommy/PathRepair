N,K=list(map(int,input().split()))
l=[0]*(K+1)
ans=0
mod=10**9+7

for x in range(K,0,-1):
    l[x]=pow((K//x),N,mod)
    for y in range(2*x,K+1,x):
        l[x]-=l[y]
        l[x]=pow(l[i],1,mod)
    ans+=l[x]*x
    ans=pow(ans,1,mod)
print(ans)