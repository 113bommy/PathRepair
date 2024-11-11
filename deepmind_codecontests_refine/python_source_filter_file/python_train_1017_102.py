n,k,s=map(int,input().split())
ans=[]
if s==10**9:
    ans=[s]*k+[1]*[n-k]
else:
    ans=[s]*k+[s+1]*(n-k)
print(*ans)