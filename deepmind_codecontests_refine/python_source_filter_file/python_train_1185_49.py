import sys
import math
input = sys.stdin.readline

# ########### ---- Input Functions ---- ############


def inp():  # For taking integer inputs
    return(int(input()))


def inlt():  # For taking List inputs
    return(list(map(int, input().split())))


def insr():  # For taking string inputs
    s = input()
    return(list(s[:len(s) - 1]))


def invr():  # For taking space separated integer variable inputs
    return(map(int, input().split()))


def inln():  # For taking multiple line inputs
    return(sys.stdin.readlines())


# ########### ---- Code ---- ############
a, b, c, d = invr()
p1 = a / b
p2 = c / d
# print(p1)
# p1 = 0.1
# p2 = 0.9

global p_win
global new_p
p_win = p1
new_p = p1

for i in range(1, 10):
    new_p = new_p * (1-p1) * (1-p2)
    p_win = p_win + new_p


print(round(p_win, ndigits=8))
