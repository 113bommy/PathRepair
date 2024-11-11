
#########
#thiking Face
from itertools import permutations

n,m=map(int,input().split())
path=set()
for _ in range(m):
    u,v=map(int,input().split())
    path|={(u-1,v-1),(v-1,u-1)}

print(sum(all((u,v) in es for u,v in zip(p,p[1:]))
          for p in permutations(range(n)) if p[0]==0))
