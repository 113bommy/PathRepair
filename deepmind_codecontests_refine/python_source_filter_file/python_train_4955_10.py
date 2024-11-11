x = input()
y = input()
temp = 0
z = []
for i in range(len(x)):
    if ord(x[i]) == ord(y[i]):
        z.append('x')
    elif ord(x[i]) >= ord(y[i]):
        z.append(y[i])
    else:
        temp = -1
        break

if temp == -1:
    print(temp)
else:
        str1 = ''.join(z)
        print(str1)

