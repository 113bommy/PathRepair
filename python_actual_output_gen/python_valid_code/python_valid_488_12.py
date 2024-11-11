import math
for i in range(int(input())):
    a = set()
    num = int(input())
    for j in range(int(math.sqrt(num)) + 1):
        if j ** 2 < num:
            a.add(j ** 2)
        if j ** 3 < num:
            a.add(j ** 3)
    print(len(a))