x=int(input())
a=[]
for i in range(1,300):
  for j in range(2,300):
    if i**j<=x:
      a.append(i**j)
print(a[-1])