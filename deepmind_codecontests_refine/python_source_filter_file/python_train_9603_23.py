from sys import stdin
import math

def readline():
    return stdin.readline()

tests = int(readline())

def solve(a, b, c, d):
    if b >= a:
        return b

    if c == d:
        m = 1
    else:
        m = math.ceil((a - b) / (c - d))

    answer = b + c * m

    if answer < a:
        return -1

    return answer


for t in range(0, tests):
    #n = int(readline())
    [a, b, c, d] = list(map(int, readline().split(' ')))
    print(solve(a, b, c, d))