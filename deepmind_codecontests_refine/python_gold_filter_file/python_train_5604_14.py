N = int(input())
L = [0,0] + [1]*55555
K = []
for i in range (len(L)):
  if L[i]:
    for j in range (2*i,len(L),i):
      L[j] = 0
    if i%5 == 1:
      K.append(i)
      if len(K) == N:
          break
print(*K)