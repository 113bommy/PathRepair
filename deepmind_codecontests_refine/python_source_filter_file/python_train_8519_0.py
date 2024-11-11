N=int(input())
A=[int(x) for x in input().split()]
ma=max(A)
mi=min(A)
ans=True

if ma-mi > 1:
  ans=False
elif ma==mi:
  if ma!=N-1 and ma*2 > N:
    ans=False
else:
  uniq=ma*N - sum(A)
  no_uni=N-uniq
  if no_uni==1:
    ans=False
  else:
    if uniq > N or 2*(ma-uniq) > no_uni:
      ans=False
if ans:
  print("Yes")
else:
  print("No")