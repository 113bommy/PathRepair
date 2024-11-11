N=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(N):
  if max(h[:i+1])==h[i]:
    ans+=1
print(ans)