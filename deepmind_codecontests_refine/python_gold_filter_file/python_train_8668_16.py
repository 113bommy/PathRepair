from math import ceil


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    x, y, k = read_ints()
    a = (k * (y + 1) - 2) // (x - 1) + 1 + k
    print(a)
