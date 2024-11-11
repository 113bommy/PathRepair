entrada = input()
contador = 1
aux = 0
a = str()
b = str()
for i in range(len(entrada) - 1):
    if entrada[i] == entrada[i+1]:
        contador = contador + 1
        if contador >= 7:
            aux = 1
            print('YES')
            break
    elif entrada[i] != entrada[i+1]:
        contador = 1
if aux != 1:
    print('NO')