from math import sqrt

p, y = [int(i) for i in input().split()]
for i in range(y, p, -1):
    if all(i % j for j in range(2, min(p, int(sqrt(i))) + 1)):
        print(i)
        break
print(-1)
