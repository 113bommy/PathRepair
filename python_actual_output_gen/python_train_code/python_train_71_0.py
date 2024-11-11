N,P = map(int,input().split())
i = int(P**(1/N))
res = []
if N == 1:
  print(P)
elif P == 1:
  print(1)
else:
  for i in range(i,1,-1):
    if P%i**N==0:
      print(i)
      break