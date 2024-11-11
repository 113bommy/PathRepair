X=int(input())
I=J=0
for i in range(-100,100):
  for j in range(-100,100):
    if i**5-j**5==X:
      I=i
      J=j
      break
print(I,J)     
  