import math

k = int(input())
l = int(input())
if abs(math.log(l, k) - int(math.log(l, k))) < 10 ** -6 and math.log(l, k) > 0:
    print('YES')
    print(int(math.log(l, k)) - 1)
else:
    print("NO")