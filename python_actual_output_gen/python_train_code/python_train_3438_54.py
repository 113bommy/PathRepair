x=int(input())
a=[1]
for i in range(2,32):
  for j in range(1,32):
    if i**j<=x:
      a.append(i**j)
print(max(a))