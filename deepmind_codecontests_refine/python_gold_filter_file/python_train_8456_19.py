import math
t = int(input())
for _ in range(t):
    n = int(input())
    for i in range(2, 30):
        if n % ((math.pow(2, i)) - 1) == 0:
            print(n // ((2**i) - 1))
            break