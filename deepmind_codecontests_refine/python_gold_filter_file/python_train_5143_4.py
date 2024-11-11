a = list(map(int, input().split()))
isGeom = True
isAlg = True
d = a[1] - a[0]
q = a[1]/a[0]
for i in range(2, 4):
  if (a[i] - a[i-1])!=d:
    isAlg = False
  if (a[i]/a[i-1])!=q:
    isGeom = False
if isAlg:
  print(a[3] + d)
elif isGeom:
  if (a[3]*q)!=int(a[3]*q): 
    print(42)
  else:
    print(int(a[3]*q))
else: print(42)