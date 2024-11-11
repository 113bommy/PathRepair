n,*a=map(int,open(0))
x=0
c=[0]*30
for i in a:
  x^=i
  c[bin(i^i-1)[::-1].rfind('1')]=1
a=0
for i in range(29,-1,-1):
  if x&2**i:
    if c[i]:
      a+=1
      x^=2**i-1
  else:
    print(-1)
    break
else:
  print(a)