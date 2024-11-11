n,r=int(input()),1e9
for i in range(1,int(n**.5)):
  if n%i==0:r=min(r,len(str(n//i)))
print(r)