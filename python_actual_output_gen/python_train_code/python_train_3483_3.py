numCases = int(input())
for i in range(numCases):
    a, b = map(int, input().split(" "))
    dif = a - b
    if a % 2 == 1:
        isAodd = True
    if b % 2 == 1:
        isBodd = True
    if dif > 0:
        if dif % 2 == 0:
            print(1) # only needs to subtract by even
        else:
            print(2) # needs to subtract by even, then add by odd
    if dif < 0:
        if dif % 2 == 1:
            print(1) # add by odd
        else:
            print(2) # add by odd, subtract by even
    else:
        print(0) # only remaining case is identical
    