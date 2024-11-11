def modificar(a):
    c = [int(i) for i in a]
    tam = len(a)//2
    esquerda = tam-1
    direita = tam
    while esquerda!=-1:
        c[esquerda]+=1
        c[direita]+=1
        if c[esquerda] >= 10 and esquerda != 0:
            c[esquerda] = 0
            c[direita] = 0
            esquerda-=1
            direita+=1
        else:
            break
    if c[0] >= 10:
        c = [1] + [0]*(tam*4 - 2) + [1]
    return [str(i) for i in c]
        

k,p = [int(i) for i in input().split()]
a = ["1","1"]
som = 0
som+=int("".join(a))
k-=1
while k != 0:
    a = modificar(a)
    som+=int("".join(a))
    k-=1
print(som%p)
