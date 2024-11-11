def SameParitySummands():
    length = int(input())
    numData = [None for _ in range(length)]
    for i in range(length):
        numData[i] = input()
        numData[i] = numData[i].split(' ')
    result = []

    for elem in numData:
        base = int(elem[0])
        order = int(elem[1])
        it = order // (base - 1)
        if order // (base - 1) * (base - 1) == order:
            result.append(base * it + order - (base - 1) * it)
        else:
            result.append(base * it + order - (base - 1) * it - 1)
    
    for elem in result:
        print(elem)

SameParitySummands()