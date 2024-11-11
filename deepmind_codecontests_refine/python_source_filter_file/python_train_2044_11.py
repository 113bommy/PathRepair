
n = int(input())
if(n < 4):
  if(n == 2):
    print(1)
    print(1, 1)
  elif(n == 3):
    print(0)
    print(1, 3)
elif(n%4 == 0):
  print(0)
  k = int(n/4)
  print(2*k, end = ' ')
  for i in range(k):
    print(n - i, i + 1, end = ' ')
elif(n%4 == 1):
  print(1)
  k = int(n/4)
  print(2*k, end = ' ')
  for i in range(k):
    print(n - i, i + 2, end = ' ')
elif(n%4 == 2):
  print(1)
  k = int(n/4)
  print(2*k + 1, 1, end = ' ')
  for i in range(k):
    print(n - i, i + 3)
elif(n%4 == 3):
  print(0)
  k = int(n/4)
  print(k + 2, 3, end = ' ')
  for i in range(k):
    print(n - i, i + 4, end = ' ')


"""
n = int(input())
ma = 'a'
mi = 'b'
for i in range(n):
  linha = input()
  linha = linha.split()
  if((linha[0] == "<=" and linha[-1] == "Y") or (linha[0] == ">" and linha[-1] == "N")):
    maior = int(linha[1])
    if(ma == 'a'):
      ma = maior
    else:
      ma = max(ma,maior)
  elif((linha[0] == "<" and linha[-1] == "Y") or (linha[0] == ">=" and linha[-1] == "N")):
    maior = int(linha[i]) + 1
    if(ma == 'a'):
      ma = maior
    else:
      ma = max(ma,maior)
  elif((linha[0] == ">" and linha[-1] == "Y") or (linha[0] == "<=" and linha[-1] == "N")):
    menor = int(linha[i]) + 1
    if(mi == 'b'):
      mi = menor
    else:
      mi = min(mi,menor)
  elif((linha[0] == ">=" and linha[-1] == "Y") or (linha[0] == "<" and linha[-1] == "N")):
    menor = int(linha[i])
    if(mi == 'b'):
      mi = menor
    else:
      mi = min(mi,menor)

if(ma == 'a'):
  print(mi)

elif(mi == 'b'):
  print(ma)

elif(mi > ma):
  print('Impossible')

elif:
  print(mi)

3 5 6 7
1 2 4 8
6


"""