a,*t=map(int,open(0).read().split())
for a,b in zip(*[iter(t)]*2):
  c=a*b
  d=int(c**.5)
  print(2*d-1-(d*(d)>=c)-(c==d*d and a!=b))