a,b,c,d,e,f = map(int,input().split())
xset = set()
yset = set()
for i in range(31):
  for j in range(16):
    if (a*i+b*j)*100 <= f:
      xset.add((a*i+b*j)*100)
xset.remove(0)
for i in range(f//c+1):
  for j in range(f//d+1):
    if c*i+c*j<=f:
      yset.add(c*i+d*j)
ll = []
maxconc = 0
maxsolution = 0
maxsolute = 0
for i in xset:
  for j in yset:
    if i+j<= f and i >= (100*j)/e and (100*j)/(i+j)>maxconc:
      maxconc = (100*j)/(i+j)
      maxsolution = i+j
      maxsolute = j
print(str(maxsolution)+' '+str(maxsolute))