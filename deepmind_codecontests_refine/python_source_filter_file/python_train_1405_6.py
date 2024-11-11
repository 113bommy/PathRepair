# char_to_dots = {
#   'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
#   'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
#   'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
#   'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
#   'Y': '-.--', 'Z': '--..', ' ': ' ', '0': '-----',
#   '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
#   '6': '-....', '7': '--...', '8': '---..', '9': '----.',
#   '&': '.-...', "'": '.----.', '@': '.--.-.', ')': '-.--.-', '(': '-.--.',
#   ':': '---...', ',': '--..--', '=': '-...-', '!': '-.-.--', '.': '.-.-.-',
#   '-': '-....-', '+': '.-.-.', '"': '.-..-.', '?': '..--..', '/': '-..-.'
# }
#from cmath import sqrt
# def printThreads(max, steps):
#     step = max // steps

#     print("{")
#     start = 0
#     for i in range(1, steps + 1):
#         print("std::thread th", i, "(sr, arr + ", start, ", arr + ", start + step, ");", sep = "")
#         start += step
#     for i in range(1, steps + 1):
#         print("th", i, ".join();", sep = "")
#     print("}")
#     index = 2
#     steps //= 2
#     while steps >= 2:
#         start = 0
#         print("{")
#         for i in range(1, steps + 1):
#             print("std::thread th", i, "(inplace, arr + ", start, ", arr + ", start + step * (index // 2), ", arr + ", start + step * 2 * (index // 2), ");", sep = "")
#             start += step * index
#         for i in range(1, steps + 1):
#             print("th", i, ".join();", sep = "")
#         print("}")
#         index *= 2
#         steps //= 2


# printThreads(1000000000, 32)

from math import *
import random


def isSorted(list):
    for i in range(1, len(list)):
        if list[i] < list[i - 1]:
            return False
    return True

def stringToList(string):
    return [int(i) for i in string.split(' ')]


def isTrue(list):
    n = len(list)
    add = 0
    if list[0] == 0:
        pass
    else:
        add = n - list[0]
    for i in range(n):
        list[i] += add
        if list[i] >= n:
            list[i] -= n
        elif list[i] < 0:
            list[i] += n

        if i >= 1 and list[i] < list[i - 1]:
            return False

        add = -add

    return True


_ = input()
inp = input()
list = stringToList(inp)
if isTrue(list):
    print("Yes")
else:
    print("No")
