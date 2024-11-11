a = input()
b = str(input())
z, o = 0, 0
ms = []
for i in b:
    if i == 'z':
        z += 1
    elif i == 'n':
        o += 1
if z != 0:
    while z > 0:
        ms.append('1')
        z -= 1
if o !=0:
    while o > 0:
        ms.append('0')
        o -= 1
print(" ".join(ms))