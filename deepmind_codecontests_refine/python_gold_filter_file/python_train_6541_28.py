from collections import defaultdict
n,c=map(int,input().split())
s=[list(map(int,input().split())) for _ in range(n)]

dd=defaultdict(lambda: [0]*(10**5+1))
for s,t,ch in s:
  for i in range(s,t+1):
    dd[ch][i]=1
ans=0
for i in range(10**5+1):
  cnt=0
  for ch in range(c+1):
    if dd[ch][i]==1:
      cnt+=1
  ans=max(ans,cnt)
print(ans)
  
  