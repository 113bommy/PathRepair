L = [2, 1]
for i in range(84):
  L.append(L[i]+L[i+1])
A = int(input())
print(L[A])