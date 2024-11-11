N,T=map(int,input().split())
t=list(map(int,input().split()))

for i in range(0,len(t)-1):
        ans+=min(t[i+1]-t[i],T)
ans+=T
print(ans)