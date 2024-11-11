a,b,c=map(int,input().split())
k=int(int())

t=0
while a >= b:
  b *= 2
  t += 1
while b >= c:
  c *= 2
  t += 1
if k >= t:
  print('Yes')
else:
  print('No')