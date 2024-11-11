while True:
    card_num = int(input())
    if(card_num == 0):
        break
    a = 0
    b = 0
    for i in range(card_num):
        comp = input()
        if(int(comp[0]) == int(comp[2])):
            a += int(comp[0])
            b += int(comp[0])
        elif(int(comp[0]) > int(comp[2])):
            a += int(comp[0]) + int(comp[2])
        elif(int(comp[0]) < int(comp[2])):
            b += int(comp[0]) + int(comp[2])
    print(str(a)+' '+ str(b))