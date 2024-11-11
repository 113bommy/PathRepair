from itertools import*
n,*a=map(int,open(0).read().split())
acc=list(accumulate(sorted(a)))[::-1]
c=1
i=0
while i<n-1:
  if acc[i]<=acc[i+1]*2:
    c+=1
    i+=1
  else:
    break
print(c)