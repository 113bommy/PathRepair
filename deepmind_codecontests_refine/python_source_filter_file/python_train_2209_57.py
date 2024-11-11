import math
import random
import sys
import collections


def In():
    return map(int, sys.stdin.readline().split())


input = sys.stdin.readline


def foodbuying():
    for _ in range(int(input())):
        x = int(input())

        print(x//9 + x)


foodbuying()
