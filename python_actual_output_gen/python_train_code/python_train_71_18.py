import sys

N,P=[int(i) for i in input().split()]
i=2
ans = 1
c=0
if N == 1:
  print(P)
  sys.exit()
while P>i*i:
  if P%i==0:
    P//=i
    c+=1
    if c==N:
      ans*=i
      c=0
  else:
    c=0
    i+=1
if P==i and c+1 ==N:
  ans*=i
print(ans)
