A, B, C, D, E, F = map(int, input().split())
V = 0
ans = ()
for i in range(F//(A*100)+1):
  for j in range(F//(B*100)+1):
    m = A*i + B*j
    m = m*100
    if m>F or m==0:
      continue
    lim = min(m*E//100, F-m)
    
    l = lim
    w = 0
    z = 0
    for x in range(lim//C+1):
      for y in range(lim//D+1):
        n = x*C+y*D
        if n>lim:
          continue
        if lim-n<l:
          l = lim-n
          w = x
          z = y
    s = w*C+z*D
    v = 100*s//(m+s)
    if v>V:
      ans = (m+s,s)
      V = v
print(*ans)