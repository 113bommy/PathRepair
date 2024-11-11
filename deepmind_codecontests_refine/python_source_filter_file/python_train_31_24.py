import math
a, b, c = map(int, input().split(' '))
print(min(math.ceil(a*c/100 - b), 0))
