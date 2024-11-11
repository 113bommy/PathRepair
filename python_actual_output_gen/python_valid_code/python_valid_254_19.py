shovle, cent = map(int,input().split())
shovle1 = shovle

if shovle % 10 == cent or shovle % 10 == 0 : ##условие для одной лопаты, слева с использованием "cent", справа без ее использования
    print(1)
elif shovle % 10 != cent or shovle % 10 == 0 :
    while shovle1 % 10 != cent and shovle1 % 10 != 0:
        shovle1 = shovle1 + shovle
        print(shovle1//shovle)