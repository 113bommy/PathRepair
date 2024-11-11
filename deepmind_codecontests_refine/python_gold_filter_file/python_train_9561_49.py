from itertools import combinations
N, K, *L = map(int, open(0).read().split())
L = [(x,y) for x,y in zip(*[iter(L)]*2)]
ans = float('inf')
for m in combinations(L,2):
  for n in combinations(L,2):
    mx = min(m,key=lambda x:x[0])[0]
    Mx = max(m,key=lambda x:x[0])[0]
    my = min(n,key=lambda x:x[1])[1]
    My = max(n,key=lambda x:x[1])[1]
    cnt = 0
    for x,y in L:
      if mx<=x<=Mx and my<=y<=My:
        cnt += 1
    if cnt>=K:
      ans = min(ans, (Mx-mx)*(My-my))
print(ans)
