
datos = input().split()
n = int(datos[0])
m = int(datos[1])

canciones = n+m-1
print(canciones)

for i in range(m):
    print(str(1)+' '+str(i+1))

for i in range(1,n):
    print(str(n)+' '+str(m))