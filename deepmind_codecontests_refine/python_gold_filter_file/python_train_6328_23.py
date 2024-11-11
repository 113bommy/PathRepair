N = int(input())
Cij = [[0 for _ in range(10)] for _ in range(10)]
for i in range(1,N+1):
  a, b = int(str(i)[0]), int(str(i)[-1])
  Cij[a][b] += 1
print(sum(Cij[i][j]*Cij[j][i] for i in range(10) for j in range(10)))