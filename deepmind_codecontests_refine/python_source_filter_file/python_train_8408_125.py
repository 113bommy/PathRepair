x=int(input())
for a in range(99):
  for b in range(-99,99):
    if a**5-b**5==x: print(a,b); exit()