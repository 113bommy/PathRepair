a = input()

b = a.split(' ')

vk = int(b[0])
va = int(b[1])

flag1 = True
flag2 = True

count = 1
while (flag1 == True):
    if(flag2 == True):
        if(vk - count >= 0):
            vk = vk - count
            count = count + 1
            flag2 = False
        else:
            flag1 = False
    else:
        if(va - count >= 0):
            va = va - count
            count = count + 1
            flag2 = True
        else:
            flag1 = False
            
if (flag2 == True):
    print('Vladik')
else:
    print('Valera')