num_cidades, num_ferrovias = map(int, input().split())
grafo = [[0]*num_cidades for i in range(num_cidades)]

for i in range(num_ferrovias):
  ferrovia_inicio, ferrovia_fim = map(int, input().split())
  grafo[ferrovia_inicio-1][ferrovia_fim-1] = 1
  grafo[ferrovia_fim-1][ferrovia_inicio-1] = 1

aux = [0]
i = 0
cidade_u = [-1]*num_cidades
cidade_u[0] = 0
while i < len(aux):
  cidade_v = aux[i]
  i += 1
  for j in range(num_cidades):
    if cidade_u[j] == -1 and grafo[cidade_v][j] != grafo[0][num_cidades-1]:
      cidade_u[j]=cidade_u[cidade_v]+1
      aux.append(j)

print(cidade_u[num_cidades-1])