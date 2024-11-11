matriz = []
s = False
for i in range(4):
  lista = input()
  matriz.append(lista)

for i in range(4):
  if str(matriz[i]).find('.xx')!=-1 or str(matriz[i]).find("x.x")!=-1 or str(matriz[i]).find("xx.")!=-1:
    s = True
    break

for i in range(4):
    aux = ''
    for j in range(4):
      aux += matriz[j][i]
    if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
      s = True
      break
aux = ''
for i in range(4):
  aux += matriz[i][i]
  if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
    s = True
    break
    
aux = ''      
for i in range(3):
  aux+= matriz[i][i+1]
if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
  s = True

aux = ''
for i in range(3):
  aux+= matriz[i+1][i]
if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
  s = True
  
aux = ''
for i in range(3):
    aux+=matriz[i][3-i]
if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
  s = True

aux = ''
for i in range(3):
    aux+=matriz[i][3-1-i]
if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
  s = True
  
aux = ''
for i in range(1,4,1):
  aux+=matriz[i][4-i]
if aux.find('.xx') != -1 or aux.find("x.x") != -1 or aux.find("xx.") != -1:
  s = True

if s == True:
  print("YES")
else:
  print("NO")
  
    