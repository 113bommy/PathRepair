import sys
import math
from statistics import mean

input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int (input ()))


def inlt():
    return (list (map (int, input ().split ())))


def insr():
    s = input()
    return (list (s[:len (s) - 1]))


def invr():
    return (map (int, input ().split ()))


n = inp()
li = []
for i in range(n):
    x, y = invr()
    li.append((x+y))
k = inp()
c = 0
for j in range(n):
    if k > li[j]:
        c = c+1
print(n-c)

