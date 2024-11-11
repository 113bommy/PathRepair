import math
n,m=[int(x) for x in input().split(' ')]
if m*math.log10(n)>n*math.log10(m):
    print('>')
elif m*math.log10(n)>n*math.log10(m):
    print('<')
else:
    print('=')