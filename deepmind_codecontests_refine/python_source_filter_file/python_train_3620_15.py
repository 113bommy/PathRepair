N = int(input())

planes = {
  'U': [],
  'R': [],
  'D': [],
  'L': []
}

for _ in range(N):
  x, y, t = input().split()
  x, y = int(x), int(y)
  planes[t].append((x, y))
  
BIG = 10**18
  
def time(ps):
  sort(ps)
  ans = BIG
  for i in range(len(ps)-1):
    y1, x1, t1 = ps[i]
    y2, x2, t2 = ps[i+1]
    
    if y1 != y2:
      continue
    
    if t1 == 1 and t2 = -1:
      ans = min(ans, x2 - x1)
  return 5*ans


ud = [(x, y, 1) for x, y in planes['U']] + [(x, y, -1) for x, y in planes['D']]
lr = [(y, x, 1) for x, y in planes['R']] + [(y, x, -1) for x, y in planes['L']]

ur = [(x+y, y-x, 1) for x, y in planes['U']] + [(x+y, y-x, -1) for x, y in planes['R']]
ul = [(x-y, y+x, 1) for x, y in planes['U']] + [(x-y, y+x, -1) for x, y in planes['L']]
rd = [(x-y, y+x, 1) for x, y in planes['R']] + [(x-y, y+x, -1) for x, y in planes['D']]
ld = [(x+y, y-x, 1) for x, y in planes['L']] + [(x+y, y-x, -1) for x, y in planes['D']]

ans = min(time(ud), time(lr), time(ur), time(ul), time(rd), time(ld))
if ans >= BIG:
  print("SAFE")
else:
  print(ans)

  