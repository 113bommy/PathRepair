X=int(input())

for a in range(10**5):
  for b in range(10**5):
    if a**5-b**5==X:print(a,b);exit()
    elif a**5+b**5==X:print(a,-b);exit()