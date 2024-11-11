matriz = []
for i in range(5):
  matriz.append(str(input()).split(" "))

k = 0
j = 0
for i in range(5):
  if matriz.count('1') > 0:
    k = matriz.index('1')
    j = i
    break

print(abs(k-2)+abs(j-2))