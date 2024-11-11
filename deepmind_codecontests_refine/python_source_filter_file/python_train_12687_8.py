Sum, Ave, Cou = 0, 0, 0
while True :
    try :
        a, b = input().split(',')
        Sum += int(a) * int(b)
        Ave += int(b)
        Cou += 1
    except : break
print(Sum)
if Ave / Cou - Ave // Cou > 0.5 : print(Ave // Cou+1)
else : print(Ave//Cou)