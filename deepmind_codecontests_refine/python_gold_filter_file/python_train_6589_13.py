tam = int(input())
pal = input()
metade = tam // 2
cont1 = 0
cont2 = 0
for i in range(0,metade):
    cont1 += int(pal[i])
for i in range(metade,tam):
    cont2 += int(pal[i])

teste = True

for i in "01235689":
    if i in pal:
        teste = False

if cont1 == cont2 and teste:
    print("YES")
else:
    print("NO")
