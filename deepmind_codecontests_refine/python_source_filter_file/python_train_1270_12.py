from collections import defaultdict

t = int(input())

for i in range(t):
 input()
 xs = [int(x) for x in input().split()]
 cs = defaultdict(list)
 for idx, x in enumerate(xs): cs[x].append(idx)

 min = None
 for item, pos in cs.items():
  for l, r in zip(pos, pos[1:]):
   if min is None or (r - l) < min:
    min = r - l
 print(-1 if min is None else min)
   