def roadCostruction(n,m):
  cidades = [list(map(int, input().split())) for _ in range(m)]
  pares = [[True for j in range(n+1)] for i in range(n+1)]
  
  for x in cidades:
    pares[x[0]][x[1]] = False
    pares[x[1]][x[0]] = False
  
  parprovavel = -1
  
  for i in range(1, n+1):
    aux = True
    for j in range(1, n+1):
      aux &= pares[i][j]
      if(not aux):
        break
    if(aux):
      parprovavel = i
      break
  
  print(n-1)
  
  for i in range(1, n + 1):
    if i != parprovavel:
      print(i, parprovavel)


n, m = map(int, input().split())
roadCostruction(n,m)