import sys

#input
parameters = list(map(int,input().split(" ")))
integerList = list(map(int, input().split(" ")))

endOfList = set(integerList[parameters[1] - 1:])#elements after index(including index)
startOfList = integerList[:parameters[1] - 1]#elements from before index(not including it)

#if there is more than one unique element after index, operation is impossible
if(len(endOfList) != 1):
    print("-1")
else:
    elements = len(startOfList)
    for i in reversed(startOfList):
        if i == integerList[parameters[1] - 1]:
            --elements
        else:
            break

    print(elements)
