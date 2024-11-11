N,K=map(int,input().split())
ans=0
for b in range(K+1,N+1):
    ans+=(N//b*(b-K))+max(N%b+1-K,0)
print(ans)