test=int(input())
lista=[]

for i in range(test):
  x,n,m=[int(q) for q in input().split()]
  if x>40:
    for i in range(n):
      x = (x//2) + 10
  if (10*m) >= x:
    lista.append("YES")
  else:
    lista.append("NO")

for i in lista:
  print(i)