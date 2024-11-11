z=int(input())
x=[]
for i in range(31):
  for j in range(10):
    if (i+1)**(j+1)<=z:
      x.append((i+1)**(j+1))
print(max(x))