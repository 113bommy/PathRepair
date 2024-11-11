def bubbleSort(c):
    for i in range(0, len(c) - 1):
        for j in range(len(c)-1, i, -1):
            if c[j][1] < c[j-1][1]:
                c[j], c[j-1] = c[j-1], c[j]


def selectionSort(c):
    for i in range(0, len(c)):
        minj = i
        for j in range(i, len(c)):
            if c[j][1] < c[minj][1]:
                minj = j
        c[i], c[minj] = c[minj], c[i]


def isStable(c1, c2):
    for i in range(0, len(c1)):
        if c1[i][0] == c2[i][0]:
            return False
    return True


import copy
n = int(input())
c1 = input().split()
c2 = copy.copy(c1)

bubbleSort(c1)
selectionSort(c2)
print(*c1)
print("Stable")
print(*c2)
print("Stable") if isStable(c1, c2) else print("Not stable")

