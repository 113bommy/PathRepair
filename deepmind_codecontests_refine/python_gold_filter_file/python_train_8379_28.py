import sys
from math import *
from itertools import product

def ints_input():
    return [int(i) for i in sys.stdin.readline().strip("\n").split(" ")]


def print_list(arr):
    sys.stdout.writelines(str(x)+" " for x in arr)
    sys.stdout.write("\n")


def fast_input(type=str):
    return type(sys.stdin.readline().strip("\n"))
n =fast_input(int)
print(int((3**(3*n) - 7**n )%(10**9 +7)))
