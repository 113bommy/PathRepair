input()
S = [int(i) for i in input()]
cnt = 0
for i in range(0, 1000):
  c = (i//100, (i//10)%10, i%10)
  f = 0
  for s in S:
    if s == c[f]:
      f += 1 
      if f==3:break 
  if f==3:cnt += 1
print(cnt)