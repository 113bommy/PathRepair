import sys
# import math
input = sys.stdin.readline


def int_array():
    return list(map(int, input().strip().split()))


def str_array():
    return input().strip().split()


def lower_letters():
    lowercase = [chr(i) for i in range(97, 97+26)]
    return lowercase


def upper_letters():
    uppercase = [chr(i) for i in range(65, 65+26)]
    return uppercase

######################### TEMPLATE ENDS HERE ##################################


for _ in range(int(input())):
    n, k = int_array()
    a = sorted(int_array())
    b = sorted(int_array())
    i = 1

    for _ in range(k):
        if b[-1] > a[0]:
            a[0] = b[-i]
            i += 1
            a = sorted(a)
        else:
            break

    print(sum(a))
