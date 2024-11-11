def combinacao(e, comb):
  if(e == comb):
    return 1
  if(e < comb):
    return 0
  
  x = e -comb
  result = 1
  if(x > comb):
    while(e > x):
      result = result * e
      e = e - 1
    while(comb > 1):
      result = result / comb
      comb = comb - 1
  else:
    while(e > comb):
      result = result * e
      e = e - 1
    while(x > 1):
      result = result / x
      x = x - 1
  
  return result

# ---------------> MAIN <-------------------------

bispos = int(input())
posicoes = []

principais = {}
secundarias = {}
for x in range(bispos):
  i, j = input().split()
  i = int(i)
  j = int(j)

  p = i - j
  s = i + j 
  if(p not in principais):
    principais[p] = 1
  else:
    principais[p] += 1
  if(s not in secundarias):
    secundarias[s] = 1
  else:
    secundarias[s] += 1

pares = 0
for key in principais:
  if(principais[key] > 1):
    pares += combinacao(principais[key], 2)

for key in secundarias:
  if(secundarias[key] > 1):
    pares += combinacao(secundarias[key], 2)

print(pares)