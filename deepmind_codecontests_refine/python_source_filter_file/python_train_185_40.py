N,P = map(int,input().split())
ans=1
i=2
if N==1:
  print(P)
  exit()
if N>=40 or P==1:
  print(1)
  exit()
  
while i<=(P**(-(1//N))):
  while P%(i**N) == 0:
    ans *= i
    P = P//(i**N)
  if i==2:
    i+=1
  else:
    i+=2
print(ans)