import re
h,w = map(int, input().split())
m=[]
d = [[0]*w for _ in range(h)]
u = [[0]*w for _ in range(h)]
for _ in range(h):
  t=[]
  for i in re.split("(#)", input()):
    if not i == "#":
      t.extend([len(i)]*len(i))
    else:
      t.append(0)
  m.append(t)

for i in range(w):
  for j in range(h):
    if m[j][i] == 0:
      d[j][i] = 0
    else:
      if j != 0:
        d[j][i] = d[j-1][i] + 1
      else:
        d[j][i] = 1

    if m[h-1-j][i] == 0:
      u[h-1-j][i] = 0
    else:
      if h-1-j == h-1:
        u[h-1-j][i] = 1
      else:
        u[h-1-j][i] = u[h-j][i] + 1
ans=0
for i in range(w):
  for j in range(h):
    ans = max(ans, u[j][i]+d[j][i]+m[j][i])
print(ans - 2)