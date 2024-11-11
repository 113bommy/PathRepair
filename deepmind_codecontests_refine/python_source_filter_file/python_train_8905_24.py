import math
n = int(input())
for i in range(n):
    if i == 0:
        print(2)
    else:
        cur = (i + 1) * (i + 2) * (i + 2) - i + 1;
        print(cur)
