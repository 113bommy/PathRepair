n = int(input())
for i in range(n):
    el = int(input())
    if el == 2 or el == 3 or el == 5 or el == 7 or el == 11:
        print(-1)
    elif el == 15:
        print(2)
    elif el % 4 == 0:
        print(el // 4)
    elif (el - 6) % 4 == 0:
        print((el - 6) // 4 + 1)
    elif (el - 9) % 4 == 0:
        print((el - 9) // 4 + 1)
    elif (el - 6 - 9) % 4 == 0:
        print((el - 9 - 9) // 4 + 2)
    else:
        print(-1)

