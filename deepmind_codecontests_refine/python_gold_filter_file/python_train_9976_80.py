x=int(input())
count=[]
for i in range(1,x+1):
  for j in range(2,100):
    if i**j<=x:
      count.append(i**j)
print(max(count))

