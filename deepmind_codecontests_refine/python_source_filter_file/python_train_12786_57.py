x=int(input())
t=0
while x>=0:
  if x%7==0:
    t=1
  x-=4
if t==0:
  print('No')
else: print('yes')