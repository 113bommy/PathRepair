import math

pixels = int(input())
mid = math.floor(math.sqrt(pixels))
for i in reversed(range(mid + 1)):
    #print(i)
    if pixels % i == 0:
        print(i, pixels// i)
        break

