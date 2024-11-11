import math

n = int(input())
l = list(map(int, input().split()))
mean = sum(l) // n
up = 0
down = 0
for x in l:
    if x > mean:
        down += math.floor(x - mean)
    elif x < mean:
        up += math.floor(mean - x)

print(min(up, down))
