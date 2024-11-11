n = int(input())
lista = []
while n:
    entrada = input()
    if entrada.startswith('cd /'):
        lista.clear()
    if entrada == "pwd":
        print('/', end='')
        for l in lista:
            print(l, end='/')
        print()
    else:
        entrada = entrada[3:]
        entrada = entrada.split('/')
        for e in entrada:
            if e != ".." and e != "":
                lista.append(e)
            else:
                if lista:
                    lista.pop()
    n -= 1
