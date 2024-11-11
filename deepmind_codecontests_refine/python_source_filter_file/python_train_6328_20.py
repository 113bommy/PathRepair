N = int(input())
Cij = [[0 for _ in range(N)] for _ in range(N)]
for i in range(1,N+1):
  a, b = int(str(i)[0]), int(str(i)[-1])
  Cij[a][b] += 1
print(sum(Cij[i][j]*Cij[j][i] for i in range(N) for j in range(N)))