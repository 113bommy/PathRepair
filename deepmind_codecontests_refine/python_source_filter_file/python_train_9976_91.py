x=int(input())
n=[]
for i in range(1,32):
  for j in range(2,10):
    if j**i<x:
      l.append(j**i)
print(max(l))