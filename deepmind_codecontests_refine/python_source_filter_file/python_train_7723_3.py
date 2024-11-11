entrada = int(input())
for k in range(entrada):
    tamanho = int(input())
    lista = list(map(int, input().split(" ")))
    lista.sort()
    tamanhomax = lista[tamanho-1]
    quadradomax = -1
    contador = 1
    for i in range(tamanho-2, -1, -1):
        contador += 1
        if(lista[i] < tamanhomax):
            tamanhomax = lista[i]
        resposta = min(tamanhomax, contador)
        if(resposta > quadradomax):
            quadradomax = resposta

    print(quadradomax)
