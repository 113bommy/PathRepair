s=list(input())
t=list(input())

r=len(t)
for ii in range(len(s)-len(t)+1):
  rr=0
  for jj in range(len(t)):
    if s[ii+jj]!=t[jj]:
      rr+=1
  if rr<r:
    r=rr
print(rr)