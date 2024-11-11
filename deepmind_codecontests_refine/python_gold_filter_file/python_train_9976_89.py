x=int(input());l=[]
for i in range(1,32):
  for j in range(2,10):
    if i**j<=x:l.append(i**j)
print(max(l))