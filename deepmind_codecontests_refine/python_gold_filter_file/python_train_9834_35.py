
onibus = [['#','#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#'],['#','#','#']]

numero = int(input())

for i in range (numero):
    embora = False
    for k in range(11):
        if '#' in onibus[k]:
            for j in range (len(onibus[k])):
                if onibus[k][j] == '#':
                    onibus[k][j] = 'O'
                    embora = True
                    break
            if embora == True:
                break


print("+------------------------+")

print("|",end="")
for i in range(11):
    print(onibus[i][0],end="")
    print(".",end="")
print("|D|)")

print("|",end="")
for i in range(11):
    print(onibus[i][1],end="")
    print(".",end="")
print("|.|")

print("|", end="")
print(onibus[0][2],end="")
print(".......................|")

print("|",end="")
print(onibus[0][3],end="")
print(".",end="")
for i in range(1,11):
    print(onibus[i][2],end="")
    print(".",end="")
print("|.|)")

print("+------------------------+")
