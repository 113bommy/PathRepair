entrada = input()
entrada = list(map(int, entrada.split()))
total = 0
for a in entrada:
  total += a
repetidos2 = []
repetidos3 = []
novo = []

for a in entrada:
  if a in novo:
    if a in repetidos2:
      repetidos3.append(a)
    else:
      repetidos2.append(a)
  novo.append(a)

maior = total

for rep in repetidos2:
  if(total - 2*rep < maior):
     maior = total - 2*rep

for rep in repetidos3:
  if(total - 3*rep < maior):
     maior = total - 2*rep

print(maior)