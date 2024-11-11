x=int(input())
n=[]
for i in range(1,32):
  for j in range(2,10):
    if i**j<=x:
      n.append(i**j)
print(max(n))