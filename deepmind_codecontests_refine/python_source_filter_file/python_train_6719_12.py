n, c = list(map(int, input().split()))

citys = list(map(int, input().split()))

aux = 1
total = 0
while(True):
  if(c+aux-1 > n-1):
    if(c-aux-1 < 0):
      break
    else:
      if(citys[c-aux-1] == 1):
        total += 1
  elif(c-aux-1 < 0):
    if(c+aux-1 > n-1):
      break
    else:
      if(citys[c+aux-1] == 1):
        total +=1
  else:
    if(citys[c+aux-1] == 1 and citys[c-aux-1] == 1):
      total += 2
  if(c+aux == n):
    break
  aux += 1
if(citys[c-1] == 1):
  total += 1
print(total)