import sys
def input(): return sys.stdin.readline()[:-1]
# def input(): return sys.stdin.buffer.readline()[:-1]

k = int(input())
# a, b = [int(x) for x in input().split()]

def f(x):
    s = 0
    while x:
        s += x % 10
        x //= 10
    return s == 10


for i in range(19, 10000000):
    if f(i):
        k -= 1
    if k == 0:
        print(i)
        exit()
