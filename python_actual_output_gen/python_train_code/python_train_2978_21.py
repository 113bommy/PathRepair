n = int(input())
for i in range(n):
    lenofstr = int(input())
    string = input()
    if(lenofstr < 11):
        print("No")
    elif(lenofstr >= 11 and (string[0] == '8')):
        print("Yes")
    else:
        index = string.find('8')
        if(index > 0):
            newlen = lenofstr - (index +1)
            if(newlen >= 11):
                print('Yes')
            else:
                print('NO')
        else:
            print("No") 