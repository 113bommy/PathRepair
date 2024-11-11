import math
a = input()
a = a.split(' ')
a[0] = int(a[0])
a[1] = int(a[1])
print(min(a[0],a[1]),abs(a[0]-a[1]//2))