a = list(map(int,input().split())); n = a[0]; m = a[1]
'Sí puedo escribir varias asignaciones en la misma línea =D El ; sirve para algo en Python'

'k será el máximo de puntos bellos que se podrán dibujar'
k = min(n,m)

print(k)
for i in range(k):
  print(i,end=" ")
  print(k-i)