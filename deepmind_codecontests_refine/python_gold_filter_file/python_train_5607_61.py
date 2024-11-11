x,y = map(int, input().split())
m = 10**10
for i in (0,1):
  for j in (0,1):
    if y*(-1)**j-x*(-1)**i>=0:
      cur = y*(-1)**j-x*(-1)**i + i + j
      if m>cur:
        m = cur
print(m)