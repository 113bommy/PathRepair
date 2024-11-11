import itertools
n,m,q=map(int,input().split())
abcd=[list(map(int,input().split())) for _ in range(q)]
l=list(range(1,m+1))
l=list(itertools.combinations_with_replacement(l,m))
ans=0
for i in l:
  kari=0
  for j in range(q):
    if i[abcd[j][1]-1]-i[abcd[j][0]-1]==abcd[j][2]:
      kari+=abcd[j][3]
  ans=max(ans,kari)
print(ans)