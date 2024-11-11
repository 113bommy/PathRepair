import math

def read_stuff():
    n = int(input())
    array = []
    str_1 = "()"
    str_2 = "(())"

    for i in range(n):
        t = int(input())
        array.append(t)

    for i in range(n):
        current = array[i]
        print(str_1 * current)
        for j in range(current - 1):
            str = str_1 * j + str_2 + str_1 * (current - j - 2)
            print(str)

read_stuff()
