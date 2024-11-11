X=int(input())

for a in range(10**4):
  for b in range(10**4):
    if a**5-b**5==X:print(a,b);exit()
    elif a**5+b**5==X:print(a,-b);exit()