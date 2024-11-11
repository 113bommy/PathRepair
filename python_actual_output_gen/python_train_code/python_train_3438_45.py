l =[]
m= range(1,32)
n =range(1,32)
x = int(input())
for i in m:
  for j in n:
    if i**j <=x:
      l.append(i**j)
print(max(l))