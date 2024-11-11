N,M=map(int,input().split())

ans=0

ans=min(N,M/2)
ans+=max(0,(M-2*ans)//4)
print(ans)