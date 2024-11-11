x=int(input())
a=[1]
for i in range(2,300):
  for j in range(2,300):
    if i**j<=x:
      a.append(i**j)
print(max(a))