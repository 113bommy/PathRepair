entrada = input()
vez = -1
total = 0
perigo = False
for i in range(len(entrada)):
    aux = int(entrada[i])
    if(vez == aux):
        total += 1
        if(total == 7):
            perigo = True
    else:
        total = 0
        vez = aux
if(perigo):
    print("YES")
else:
    print("NO")
