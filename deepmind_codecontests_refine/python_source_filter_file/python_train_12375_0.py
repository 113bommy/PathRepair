import math
while True:
    try:
        v = float(input())
    except:
        break
    print(math.ceil(v ** 2 / 98 + 1))