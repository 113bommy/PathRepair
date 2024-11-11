import math
x = int(input())
for a in range(x):
    y = str(input()).split(" ")
    z = str(input()).split(" ")
    dias = int(y[1])
    vetor = [int(z[b]) for b in range(len(z))]
    total = vetor[0]
    for b in range(1, len(z)):
        if(dias > 0):
            custo = vetor[b]*b
            if(custo <= dias):
                total += vetor[b]
                dias -= custo
            else:
                total += (dias//b)
                dias -= (dias//b)*b
        else:
            break;
    print(total)
