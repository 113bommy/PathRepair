from itertools import permutations
n,m=map(int,input().split())
s=[set(map(int,input().split())) for _ in range(n)]

ans=0
x=[i for i in range(2,n+1)]
cand=permutations(x)
for i in cand:
  crnt=1
  for nxt in i:
    if set([crnt,nxt]) in s:
      crnt=nxt
    else:
      break
  else:
    ans+=1
print(ans)