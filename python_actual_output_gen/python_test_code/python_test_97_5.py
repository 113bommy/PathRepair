cantidad = int('5')
lineas = []
for i in range(cantidad):
    linea = input()
    lineas.append(linea.split(' '))
finales = []

for i in lineas:
    esta = False
    for j in finales:
        if i[0] in j:
            esta = True
            j.append(i[1])
    if not esta:
        finales.append(i)

print(len(finales))
for i in finales:
    print(i[0] + ' ' + i[-1])