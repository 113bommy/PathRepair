import math

i = int(input())


while i != 0:
    x = int(input())
    if x < 3:
        print(0)
        i -= 1
    elif x % 2 != 0:
        print((x - 1) / 2)
        i -= 1
    else:
        print(int(math.floor((x - 1) / 2)))
        i -= 1
