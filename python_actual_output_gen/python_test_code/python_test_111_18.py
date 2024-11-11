_,h=open(0)
m=t=b=0
for h in map(int,h.split()):
  t=t*(h<=b)+1
  m=max(m,t)
  b=h
print(m)