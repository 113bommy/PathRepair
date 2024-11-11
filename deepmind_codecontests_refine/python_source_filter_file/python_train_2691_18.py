n,a,b,*h=map(int,open(0).read().split())
i,j=0,max(h)*n//a
while True:
  if j-i<2:
    print(j)
    break
  k=c=(j+i+1)//2
  for t in h:
    t-=b*k
    if t>0:
      c+=-t//(a-b)
  if c>=0:
    j=k
  else:
    i=k