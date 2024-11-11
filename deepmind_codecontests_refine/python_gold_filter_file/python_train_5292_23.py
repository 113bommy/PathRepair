n=int(input())
rem=10**10
S=0
allissame=0
for i in range(n):
  a,b=map(int,input().split())
  S+=a
  if a<b:
    allissame|=1
    continue
  elif a>b:
    if rem > b:
      rem=b
    allissame|=1
  else:pass
if not allissame:
  print(0)
else:
  print(S-rem)
