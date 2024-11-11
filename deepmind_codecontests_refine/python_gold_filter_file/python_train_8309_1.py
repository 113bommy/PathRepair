n,q,*t=map(int,open(0).read().split())
for v,w in zip(t[::2],t[1::2]):
 while n>1and v!=w:
  if v>w:v,w=w,v
  w=(w+n-2)//n
 print(v)