(n,_),*t=[t.split()for t in open(0)]
n=int(n)
for i in range(10**(n-1)-(n<2),10**n):
  i=str(i)
  for s,c in t:
    if i[int(s)-1]!=c:
      break
  else:
    print(i)
    break
else:
  print(-1)