n = int(input())
linhaCheia = 'E'*n
linhas = [input() for k in range(n)]

if not linhaCheia in linhas:
  for i in range(n):
    lessEvil = linhas[i].find('.')
    print(i + 1, lessEvil + 1)
else:
  colunas = ["".join(k) for k in list(zip(*linhas))]
  if linhaCheia in colunas:
    print(-1)
  else:
    for i in range(n):
      lessEvil = colunas[i].find('.')
      print(lessEvil + 1, i + 1)
  
