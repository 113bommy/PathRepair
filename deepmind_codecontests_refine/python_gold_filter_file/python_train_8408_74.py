X=int(input())
I=J=0
for i in range(-300,300):
  for j in range(-300,300):
    if i**5-j**5==X:
      I=i
      J=j
      break
print(I,J)    