X=int(input())
c=[]
for i in range(0,X):
  for k in range(2,10):
    if (i+1)**k<=X:
      c.append((i+1)**k)
print(max(c))
  