palavras = input().split()
dicionario = {}
for line in range(int(palavras[1])):
    termo = input().split()
    dicionario[termo[0]] = termo[1]
texto = input().split()
nova = []
#print(dicionario)
for entrada in texto:
    if dicionario[entrada]:
        if len(dicionario[entrada]) > len(entrada):
            nova.append(entrada)
        else:
            nova.append(dicionario[entrada])
    else:
        for l1, l2 in dicionario.items():
            if l2 == entrada:
                if len(entrada) < len(l1):
                    nova.append(entrada)
                else:
                    nova.append(l1)
print(*nova)
