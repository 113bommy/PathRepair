list=[]

def gg():
    for i in range(len(list)):
        for j in range(i+1,len(list)):
            if list[i]==list[j]:
                return [i,j]
    return False

def cal():
    global list
    input()
    list = [int(x) for x in input().split()]
    if 2048 in list:
        return 'YES'
    indicator = gg()
    while indicator:
        if 2048 in list:
            return 'YES'
        list.append(list.pop(indicator[0]) + list.pop(indicator[1] - 1))
        indicator = gg()

    if 2048 in list:
        return 'YES'

    return 'NO',list

for i in range(int(input())):
    print(cal())