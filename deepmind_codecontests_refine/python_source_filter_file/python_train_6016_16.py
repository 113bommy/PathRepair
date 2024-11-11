import itertools
s=list(map(int,input().split()))
t=[list(map(int,input().split())) for i in range(s[2])]
li=[x for x in range(1,s[0]+1)]
lity=list(itertools.combinations_with_replacement(li,s[0]))
ans=0
for k in lity:
  vmax=0
  for l in t:
    if k[l[1]-1]-k[l[0]-1]==l[2]:
      vmax+=l[3]
  ans=max(ans,vmax)
print(ans)