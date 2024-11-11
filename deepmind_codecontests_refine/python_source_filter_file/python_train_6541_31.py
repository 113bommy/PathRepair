from collections import defaultdict
n,C=map(int,input().split())
s=[list(map(int,input().split())) for _ in range(n)]

dd=defaultdict(lambda: [0]*(10**5+1))
for s,t,c in s:
  for i in range(s-1,t+1):
    dd[c][i]=1
ans=0
for i in range(10**5+1):
  cnt=0
  for ch in range(C+1):
    if dd[ch][i]==1:
      cnt+=1
  ans=max(ans,cnt)
print(ans)
  
  