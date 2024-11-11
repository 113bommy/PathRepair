import math
while True:
    try:
        v = float(input())
        t = v / 9.8
        y = 4.9 * (t**2)
        N = y  / 5 + 1
        print(math.ceil(N))
    except EOFError:
        break