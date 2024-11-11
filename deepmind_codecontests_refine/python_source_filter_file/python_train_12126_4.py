import string

def main():
    n = int(input())
    # n: cantidad de nombres

    broke = False
    comparar = ""
    letras = {}
    alfabeto = list(string.ascii_lowercase)
    c = 0

    # se inicializa el dict con las letras del alfabeto y un set
    for i in alfabeto:
        letras[i] = set()

    # se reciben los n nombres
    for _ in range(n):
        nombre = input()

        # Si hay un nombre anterior, se compara
        if (c > 0):
            # Se comparan las letras de ambos nombres, se va avanzando
            for i, j in zip(nombre, comparar):
                # Si tenemos dos diferentes se agregan al dict
                if (i != j):
                    letras[i].add(j)
                    broke = True
                    break
            
            # Si se llega al final de ambas palabras y se encuentra que la palabra
            # anterior es mayor a la actual entonces es imposible encontrar una sol
            if ((broke == False) and (comparar > nombre)):
                return("Impossible")
        
        comparar = nombre
        c += 1

    # a: lista con las letras que no tienen len en el dict
    a = []
    for key, value in letras.items():
        if (len(value) == 0):
            a.append(key)

    # b: la diff del alfabeto con a / las letras que si tienen len en el dict
    b = list(set(alfabeto) - set(a))
    b.sort()
    
    sol = []
    # Se arma la sol
    while (len(a) > 0):
        d = a.pop()
        sol.append(d)

        # Iteramos sobre b buscando si aun hay asociaciones con las de a
        for i in b:
            # Se saca el que ya esta en la sol del dict
            if (d in letras[i]):
                letras[i].remove(d)
                # Si esa letra ya no tiene asociados se agrega en a y se quita de b
                if (len(letras[i]) == 0):
                    a.append(i)
                    b.remove(i)

    if (len(b) > 0):
        return("Impossible")
    
    return("".join(sol))

print(main())