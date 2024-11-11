__author__ = 'Obriel Muga'

if __name__ == '__main__':
    lista = []
    filas,columnas = list(map(int,input().strip().split()))
    UL = False
    DU = False
    IZQ = 10000000000000
    DER = -1000000000000
    for i in range(filas):
        linea = input()
        if (UL):
            lista.append(linea)
        elif (not UL and '*' in linea):
            lista.append(linea)
            UL = True
    for i in range(len(lista) - 1, -1,-1):
        if ("*" not in lista[i]):
            del lista[i]
        else:
            break
    for valor in lista:
        a = valor.find('*')
        b = valor.rfind('*')
        if (a >= 0 and a <= IZQ):
            IZQ = a
        if (b >= 0 and b >= DER):
            DER = b
    for i in lista:
        print(i[IZQ:DER+1])
            
            
        
