n,a,b=map(int,input().split())
ans=b*(n//(a+b))
ans+=min(b,n%(a+b))
print(ans)