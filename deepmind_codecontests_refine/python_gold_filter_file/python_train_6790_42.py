import math

for _ in [0]*int(input()):
    a, b = map(int, input().split())
    print(int(math.log10(b+1)) * a)