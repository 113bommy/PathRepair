lectura= lambda: map(int,input().split())
n,p,q=lectura()
palabra= input()
prioridad=-1
prio2=-1
for i in range(0,(len(palabra)// p) + 1):
    if (len(palabra)- p*i) % q == 0:
        prioridad= i
        prio2= (len(palabra)- p*i)// q
        break
if prioridad == -1:
    print(-1)
else:
    print(prioridad + prio2)
    for i in range(0, prioridad):
        inicio= i*p
        final= (i+1)*p
        print(palabra[inicio:final])
    for i in range(0, prio2):
        inicio= ( (prioridad*p) + (i*q) )
        final= ( (prioridad*p) + ((i + 1)*q) )
        print(palabra[inicio:final])