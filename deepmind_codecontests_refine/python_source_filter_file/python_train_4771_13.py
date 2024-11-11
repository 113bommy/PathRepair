n=int(input())
ans=n
for i in range(n):
  cc=0
  t=i
  while t>0:
    cc=cc+t%6
    t=t//6
  t=n-i
  while t>0:
    cc=cc+t%9
    t=t//9
  if ans>cc:
    ans=cc
print(ans)