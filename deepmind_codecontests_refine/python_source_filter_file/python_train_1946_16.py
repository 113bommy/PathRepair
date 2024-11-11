import math
x, y = map(int, input().split())

if x*math.log10(y) > y*math.log10(x):
    print('>')
elif x*math.log10(y) < y*math.log10(x):
    print('<')
else:
    print('=')