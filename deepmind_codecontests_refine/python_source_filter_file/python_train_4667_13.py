H, W = map(int,input().split())
A = [input() for _ in range(N)]

tmp = []
for a in zip(*A):
  if(a.count("#") > 0):
    tmp.append("".join(a))
tmp2 = []
for t in zip(*tmp):
  if(t.count("#") > 0):
    tmp2.append("".join(t))
print("\n".join(tmp2))