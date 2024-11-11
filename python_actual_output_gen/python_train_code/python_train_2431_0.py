numero=int(input())
letras = input()
lista=list(letras)
a=lista.count("A")
t=lista.count("T")
g=lista.count("G")
c=lista.count("C")
numeroSig=max(a,t,g,c)
listaACGT=[a,t,g,c]
z=0
for i in listaACGT:
    if(i==numeroSig):
        z+=1
print(pow(z, numero, 100000007))