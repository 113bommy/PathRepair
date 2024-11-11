x=int(input())
l=[]
for i in range(1,40):
  for j in range(2,40):
    if i**j<=x:
      l.append(i**j)
print(max(l))