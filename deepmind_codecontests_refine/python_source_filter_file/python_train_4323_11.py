import math

def solve():
    n = int(input())
    for i in range(100):
        if n & 2 ** i:
            print(i + 1, end = " ")
    print()


t = 1
# t = int(input())
while True:
    solve()
    t -= 1
    if t <= 0:
        break
